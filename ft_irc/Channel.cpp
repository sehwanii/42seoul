#include "./includes/Server.hpp"

Channel::Channel(std::string str_n, std::string str_p)
{
	// Constructor
	this->name = str_n;
	this->pass = str_p;
	this->user_limit = 0;
	this->topic = "";
	this->message = "";
	this->mode['i'] = 0;
	this->mode['t'] = 0;
	this->mode['k'] = 0;
	this->mode['o'] = 0;
	this->mode['l'] = 0;
}

Channel::~Channel(void)
{
	// Destructor
}

// -- GETTERS --

int	Channel::getUserLimit(void)
{
	return (user_limit);
}

std::string	Channel::getTopic(void)
{
	return (topic);
}

std::string	Channel::getPass(void)
{
	return (pass);
}

std::map<char, int> Channel::getMode(void)
{
	return (mode);
}

std::vector<User> Channel::getUsers(void)
{
	return (users);
}

std::vector<User> Channel::getOperators(void)
{
	return (operators);
}

std::string Channel::getName(void) const
{
	return (name);
}

// -- SETTERS --

void Channel::setUserLimit(int num)
{
	user_limit = num;
}

void Channel::setTopic(std::string str)
{
	topic = str;
}

void Channel::setPass(std::string str)
{
	pass = str;
}

void Channel::setMode(char m, char sign)
{
	std::map<char, int>::iterator it;
	for (it = this->mode.begin(); it != this->mode.end(); it++)
	{
		if (it->first == m)
		{
			if (sign == '+')
				it->second = 1;
			else
				it->second = 0;
		}
	}
}

// -- MEMEBR FUNCTIONS --

void Channel::addUser(User new_user)
{
	if (operators.size() == 0)
		operators.push_back(User(new_user));
	if (this->isMode('l'))
	{
		if (this->user_len() == this->user_limit)
		{
			sendErrorMessage(new_user._fd, (this->getName() + CHAN_FULL), ERR_CHANNELISFULL);
			return ;
		}
	}
	users.push_back(User(new_user));
	std::string chan_message = "\n - WELCOME TO THE CHANNEL " + this->name + "! - \n";
	message = "List of Commands                                             Usage\n"
		"PRIVMSG - message user(s) in the channel           PRIVMSG <receiver>{,<receiver>} <text to be sent>\n"
		"MODE (o) - change the mode of the channel         MODE <channel> <+/-mode> {argument}\n"
		"TOPIC (o) - change the topic of the channel        TOPIC <channel> <topic>\n"
		"INVITE (o) - invite another user to the channel   INVITE <nickname> <channel>\n"
		"KICK (o) - eject a client from a channel          KICK <channel> <user> [<comment>] \n\n";
	send(new_user._fd, (chan_message + message).c_str(), strlen(message.c_str()) + strlen(chan_message.c_str()), 0);
}

void Channel::kickUser(std::string user_kick, const std::vector<std::string>& splitmsg, User user)
{
	std::vector<User>::iterator it;
	std::vector<User>::iterator it_s;
	std::vector<User>::iterator it_o;
	unsigned long i = 3;

	for(it_s = this->users.begin(); it_s != this->users.end(); ++it_s)
	{
		if (it_s->nickName == user_kick)
		{
			if (this->isOperator(user) != 1)
			{
				sendErrorMessage(user._fd, OP_ERR_M, ERR_CHANOPRIVSNEEDED);
				return ;
			}
			else
			{
				if(user.nickName == user_kick)
				{
					sendErrorMessage(user._fd, "You cannot kick yourself\n", ERR_CANNOTSENDTOCHAN);
					return ;
				}
				send(it_s->_fd, "You have been kicked from the channel\n", strlen("You have been kicked from the channel\n"), 0);
				if (splitmsg.size() > 3)
					send(it_s->_fd, "Reason for kicking: ", strlen("Reason for kicking: "), 0);
				while (i < splitmsg.size())
				{
					send(it_s->_fd, (splitmsg.at(i)).c_str(), strlen((splitmsg.at(i)).c_str()), 0);
					send(it_s->_fd, " ", strlen(" "), 0);
					i++;
				}
				send(it_s->_fd, "\n", strlen("\n"), 0);
				this->users.erase(it_s);
				for (it_o = this->operators.begin(); it_o != this->operators.end(); ++it_o)
					if (it_o->nickName == user_kick)
						this->operators.erase(it_o);
				return ;
			}
		}
	}
	if (it_s == this->users.end())
		sendErrorMessage(user._fd, (user_kick + NO_USR_M), ERR_NOSUCHNICK);
}

void Channel::exec_mode(std::string mode, User &user, std::string arg)
{
	if (mode[1] == 'k')
	{
		if (mode[0] == '+')
		{
			if (arg == "")
				sendErrorMessage(user._fd, "Key for Channel not provided\n", TOO_MANY_ARGS);
			else
				this->pass = arg;
		}
		else
			this->pass = "";
	}
	else if (mode[1] == 'o')
	{
		std::vector<User>::iterator it_s;
		for(it_s = this->users.begin(); it_s != this->users.end(); ++it_s)
		{
			if (it_s->nickName == arg)
				break ;
		}
		if (it_s != this->users.end())
		{
			if (mode[0] == '+')
			{
					if (this->isOperator(*it_s))
						send(user._fd, "User is already an Operator\n", strlen("User is already an Operator\n"), 0);
					else
					{
						this->operators.push_back(*it_s);
						send(it_s->_fd, ("You are an operator of " + this->name + " channel \n").c_str(), strlen(("You are an operator of " + this->name + " channel \n").c_str()), 0);
					}
			}
			else
			{
				it_s = this->op_in_chan(it_s->_fd);
				if (it_s != this->operators.end())
				{
					if (it_s->nickName != user.nickName)
					{
						send(it_s->_fd, ("You are no longer an operator of " + this->name + " channel \n").c_str(), strlen(("You are no longer an operator of " + this->name + " channel \n").c_str()), 0);
						this->operators.erase(it_s);
					}
					else
						send(user._fd, "Cannot remove yourself from operators\n", strlen("Cannot remove yourself from operators\n"), 0);
				}
				else
					send(user._fd, "User is not an Operator\n", strlen("User is not an Operator\n"), 0);
			}
		}
		else
			sendErrorMessage(user._fd, (arg + NO_USR_M), ERR_NOSUCHNICK);
	}
	else if (mode[1] == 'l')
	{
		if (mode[0] == '+')
		{
			if (std::atoi(arg.c_str()) <= 0)
				send(user._fd, "Invalid Limit\n", strlen("Invalid Limit\n"), 0);
			else
				this->user_limit = std::atoi(arg.c_str());
		}
	}
	this->setMode(mode[1], mode[0]);
}

int Channel::user_len(void)
{
	int len = 0;

	for (it_u = users.begin(); it_u != users.end(); it_u++)
		len++;
	return (len);
}

int Channel::isInvited(User user)
{
	std::vector<User>::iterator it;
	for (it = this->invites.begin(); it != this->invites.end(); it++)
	{
		if (it->nickName == user.nickName)
			return (1);
	}
	return (0);
}

int Channel::isMode(char m)
{
	std::map<char, int>::iterator it;
	for (it = this->mode.begin(); it != this->mode.end(); it++)
	{
		if (it->first == m)
		{
			if (it->second == 1)
				return (1);
			else if (it->second == 0)
				return (0);
		}
	}
	return (2);
}

int Channel::isOperator(User user)
{
	std::vector<User>::const_iterator it;
	for (it = this->operators.begin(); it != this->operators.end(); it++)
	{
		if (it->nickName == user.nickName)
			return (1);
	}
	return (0);
}

int Channel::isUser(User user)
{
	std::vector<User>::const_iterator it;
	for (it = this->users.begin(); it != this->users.end(); it++)
	{
		if (it->nickName == user.nickName)
			return (1);
	}
	return (0);
}

std::vector<User>::iterator Channel::user_in_chan(int fd)
{
	for (this->it_u = this->users.begin(); this->it_u != this->users.end(); it_u++)
	{
		if (it_u->_fd == fd)
			return (it_u);
	}
	return (it_u);
}

std::vector<User>::iterator Channel::op_in_chan(int fd)
{
	for (this->it_o = this->operators.begin(); this->it_o != this->operators.end(); it_o++)
	{
		if (this->it_o->_fd == fd)
			return (it_o);
	}
	return (it_o);
}

std::vector<User>::iterator Channel::inv_in_chan(int fd)
{
	for (this->it_i = this->invites.begin(); this->it_i != this->invites.end(); it_i++)
	{
		if (this->it_i->_fd == fd)
			return (it_i);
	}
	return (it_i);
}