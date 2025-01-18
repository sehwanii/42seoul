
#include "./includes/Server.hpp"
#include "./includes/Command.hpp"
#include "./includes/User.hpp"

Command::Command(void)
{
	// defualt constructor
	this->message = "";
	
}

Command::~Command(void)
{
	// destructor
}

// - MEMBER FUNCTIONS -

std::vector<std::string> Command::ft_split(std::string str, char delimiter)
{
	std::vector<std::string> substrings;
	std::string substring = "";
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] != delimiter)
		{
			substring += str[i];
		}
		else
		{
			substrings.push_back(substring);
			while (str[i] == delimiter)
				i++;
			i--;
			substring = "";
		}
	}
	substrings.push_back(substring);
	return (substrings);
}

std::vector<Channel>::iterator Command::chan_exist(std::string channel)
{
	for (this->chan_it = Server::_channels.begin(); this->chan_it != Server::_channels.end(); chan_it++)
	{
		if (chan_it->getName() == channel)
			return chan_it;
	}
	return chan_it;
}

std::vector<User>::iterator Command::user_exist(std::string nick)
{
	for (this->user_it = Server::_users.begin(); this->user_it != Server::_users.end(); user_it++)
	{
		if (user_it->nickName == nick)
			return user_it;
	}
	return user_it;
}

void Command::join(std::string channel_s, std::string key_s, User user)
{
	std::vector<std::string> channel_split = ft_split(channel_s, ',');
	std::vector<std::string> key_split = ft_split(key_s, ',');
	std::vector<Channel>::iterator it;
	std::vector<User>::iterator it_i;
	std::vector<std::string>::iterator it_s;
	std::vector<std::string>::iterator it_k = key_split.begin();
	
	// check if channel exists
	for (it_s = channel_split.begin(); it_s != channel_split.end(); it_s++)
	{
		if ((it_s->at(0) != '#' && it_s->at(0) != '&'))
			send(user._fd, INVALID_CHAN, strlen(INVALID_CHAN), 0);
		else if(it_s->size() <= 1)
			send(user._fd, INVALID_CHAN_NAME, strlen(INVALID_CHAN_NAME), 0);
		else
		{
			it = chan_exist(*it_s);
			if (it != Server::_channels.end())
			{
				if (it->isUser(user))
				{
					sendErrorMessage(user._fd, (user.nickName + " " + it->getName() + YES_USR_M), ERR_USERONCHANNEL);
					return ;
				}
				if (it_k != key_split.end() && key_s != "")
				{
					if (it->isMode('k') == 1)
					{
						if (*it_k == it->getPass())
						{
							if (it->isMode('i') == 1)
							{
								if (it->isInvited(user))
								{
									it_i = it->inv_in_chan(user._fd);
									if (it_i != it->invites.end())
										it->invites.erase(it_i);
									it->addUser(user);
								}
								else
									sendErrorMessage(user._fd, (it->getName() + NO_INV_M), ERR_INVITEONLYCHAN);
							}
							else
								it->addUser(user);
						}
						else
							sendErrorMessage(user._fd, (it->getName() + NO_KEY_M), ERR_BADCHANNELKEY);
					}
					else
						sendErrorMessage(user._fd, "Key Not required to join channel\n", ERR_BADCHANNELKEY);
					it_k++;
				}
				else
				{
					if (it->isMode('i') == 1)
					{
						if (it->isInvited(user))
						{
							if (it->isMode('k') == 1)
								sendErrorMessage(user._fd, (it->getName() + NO_KEY_M), ERR_BADCHANNELKEY);
							else
							{
								it_i = it->inv_in_chan(user._fd);
								if (it_i != it->invites.end())
									it->invites.erase(it_i);
								it->addUser(user);
							}
						}
						else
							sendErrorMessage(user._fd, (it->getName() + NO_INV_M), ERR_INVITEONLYCHAN);
					}
					else
					{
						if (it->isMode('k') == 1)
								sendErrorMessage(user._fd, (it->getName() + NO_KEY_M), ERR_BADCHANNELKEY);
						else
							it->addUser(user);
					}
				}
			}
			else
			{
				if (it_k != key_split.end())
				{
					Channel new_channel(*it_s, *it_k);
					new_channel.addUser(user);
					Server::_channels.push_back(new_channel);
					it_k++;
				}
				else
				{
					Channel new_channel(*it_s, "");
					new_channel.addUser(user);
					Server::_channels.push_back(new_channel);
				}
			}
		}
	}
}

void Command::kick(std::string channel, std::string user_kick, const std::vector<std::string>& splitmsg, User user)
{
	std::vector<Channel>::iterator it_c;

	it_c = chan_exist(channel);
	if (it_c != Server::_channels.end())
		it_c->kickUser(user_kick, splitmsg, user);
	else
		sendErrorMessage(user._fd, (channel + NO_CHAN_M), ERR_NOSUCHCHANNEL);
}

void Command::invite(std::string user, std::string channel, User user_o)
{
	std::vector<Channel>::iterator it_c;
	std::vector<User>::iterator it_s;

	it_c = chan_exist(channel);
	if (it_c != Server::_channels.end())
	{
		it_s = user_exist(user);
		if (it_s != Server::_users.end())
		{
			if (it_c->isOperator(user_o) != 1)
				sendErrorMessage(user_o._fd, OP_ERR_M, ERR_CHANOPRIVSNEEDED);
			else
			{
				if (it_c->isUser(*it_s))
					sendErrorMessage(user_o._fd, (user + " " + channel + YES_USR_M), ERR_USERONCHANNEL);
				else
				{
					if (it_c->isMode('i') == 1)
					{
						if (it_c->isInvited(*it_s))
							send(user_o._fd, "User is already invited\n", strlen("You are already invited\n"), 0);
						else
						{
							message = "You're invited to the Channel " + channel + " \n";
							send(it_s->_fd, message.c_str(), strlen(message.c_str()), 0);
							it_c->invites.push_back(*it_s);
						}
					}
					else
						send(user_o._fd, "Channel is not on +i mode\n", strlen("Channel is not on +i mode\n"), 0);
				}
			}
		}
		else
			sendErrorMessage(user_o._fd, (user + NO_USR_M), ERR_NOSUCHNICK);
	}
	else
		sendErrorMessage(user_o._fd, (channel + NO_CHAN_M), ERR_NOSUCHCHANNEL);
	
}

void Command::topic(std::string channel, std::string topic, User user)
{
	std::vector<Channel>::iterator it_c;

	it_c = chan_exist(channel);
	if (it_c != Server::_channels.end())
	{
		if (it_c->isMode('t') == 1)
		{
			if (it_c->isOperator(user) == 1)
			{
				if (topic != "")
				{
					it_c->setTopic(topic);
					message = "Topic of channel " + channel + "changed." + "\n";
					send(user._fd, message.c_str(), strlen(message.c_str()), 0);
				}
				else
				{
					message = "Channel " + channel + "'s topic: " + it_c->getTopic() + "\n";
					send(user._fd, message.c_str(), strlen(message.c_str()), 0);
				}
			}
			else
				sendErrorMessage(user._fd, OP_ERR_M, ERR_CHANOPRIVSNEEDED);
		}
		else
		{
			if (topic != "")
			{
				it_c->setTopic(topic);
				message = "Topic of channel " + channel + " changed." + "\n";
				send(user._fd, message.c_str(), strlen(message.c_str()), 0);
			}
			else
			{
				message = "Channel " + channel + "'s topic: " + it_c->getTopic() + "\n";
				send(user._fd, message.c_str(), strlen(message.c_str()), 0);
			}
		}
	}
	else
		sendErrorMessage(user._fd, (channel + NO_CHAN_M), ERR_NOSUCHCHANNEL);
}

void Command::privmsg(std::string reciever, const std::vector<std::string>& splitmsg, User user)
{
	std::vector<std::string> reciever_split = ft_split(reciever, ',');
	std::vector<Channel>::iterator it_c;
	std::vector<User>::iterator it_u;
	std::vector<std::string>::iterator it_s;
	unsigned long i = 2;

	for (it_s = reciever_split.begin(); it_s != reciever_split.end(); it_s++)
	{
		it_u = user_exist(*it_s);
		if (it_u == Server::_users.end())
		{
			it_c = chan_exist(reciever);
			if (it_c != Server::_channels.end())
			{
				if (it_c->isUser(user))
				{
					std::vector<User> temp_users = it_c->getUsers();
					for(std::vector<User>::iterator it = temp_users.begin(); it != temp_users.end(); ++it)
					{
						if(it->_fd != user._fd)
						{
							send(it->_fd, (user.nickName + " :" ).c_str(), strlen((user.nickName + " :" ).c_str()), 0);
							while (i < splitmsg.size())
							{
								send(it->_fd, (splitmsg.at(i)).c_str(), strlen((splitmsg.at(i)).c_str()), 0);
								send(it->_fd, " ", strlen(" "), 0);
								i++;
							}
							send(it->_fd, "\n", strlen("\n"), 0);
							i = 2;
						}
					}
				}
				else
					sendErrorMessage(user._fd, (it_c->getName() + NOT_CHAN_USR), ERR_CANNOTSENDTOCHAN);
			}
		}
		else
		{
			if(user._fd == it_u->_fd)
				send(it_u->_fd, "can't send message to same user\n", strlen("can't send message to same user\n"), 0);
			else
			{
				send(it_u->_fd, (user.nickName + " :" ).c_str(), strlen((user.nickName + " :" ).c_str()), 0);
				while (i < splitmsg.size())
				{
					send(it_u->_fd, (splitmsg.at(i)).c_str(), strlen((splitmsg.at(i)).c_str()), 0);
					send(it_u->_fd, " ", strlen(" "), 0);
					i++;
				}
				send(it_u->_fd, "\n", strlen("\n"), 0);
				i = 2;
			}
		}
		if (it_u == Server::_users.end() && it_c == Server::_channels.end())
			sendErrorMessage(user._fd, (*it_s + " :No such nickname" + " or channel.\n"), ERR_NOSUCHNICK);
	}
}

void Command::notice(std::string reciever, const std::vector<std::string>& splitmsg, User user)
{
	std::vector<std::string> reciever_split = ft_split(reciever, ',');
	std::vector<Channel>::iterator it_c;
	std::vector<User>::iterator it_u;
	std::vector<std::string>::iterator it_s;
	unsigned long i = 2;

	for (it_s = reciever_split.begin(); it_s != reciever_split.end(); it_s++)
	{
		it_u = user_exist(*it_s);
		if (it_u == Server::_users.end())
		{
			it_c = chan_exist(reciever);
			if (it_c != Server::_channels.end())
			{
				if (it_c->isUser(user))
				{
					std::vector<User> temp_users = it_c->getUsers();
					for(std::vector<User>::iterator it = temp_users.begin(); it != temp_users.end(); ++it)
					{
						if(it->_fd != user._fd)
						{
							send(it->_fd, (user.nickName + " NOTICE: " ).c_str(), strlen((user.nickName + " NOTICE: " ).c_str()), 0);
							while (i < splitmsg.size())
							{
								send(it->_fd, (splitmsg.at(i)).c_str(), strlen((splitmsg.at(i)).c_str()), 0);
								send(it->_fd, " ", strlen(" "), 0);
								i++;
							}
							send(it->_fd, "\n", strlen("\n"), 0);
							i = 2;
						}
					}
				}
			}
		}
		else
		{
			if(user._fd != it_u->_fd)
			{
				send(it_u->_fd, (user.nickName + " NOTICE: " ).c_str(), strlen((user.nickName + " NOTICE: ").c_str()), 0);
				while (i < splitmsg.size())
				{
					send(it_u->_fd, (splitmsg.at(i)).c_str(), strlen((splitmsg.at(i)).c_str()), 0);
					send(it_u->_fd, " ", strlen(" "), 0);
					i++;
				}
				send(it_u->_fd, "\n", strlen("\n"), 0);
				i = 2;
			}
		}
	}
}

void Command::mode(std::string channel, std::string mode, User user, std::string arg)
{
	std::vector<Channel>::iterator it_c;

	if (mode.size() != 2 && (mode[0] != '+' && mode[0] != '-'))
	{
		sendErrorMessage(user._fd, (mode + MODE_ERR_M), ERR_UNKNOWNMODE);
		return ;
	}
	it_c = chan_exist(channel);
	if (it_c == Server::_channels.end())
		sendErrorMessage(user._fd, (channel + NO_CHAN_M), ERR_NOSUCHCHANNEL);
	else
	{
		if (it_c->isOperator(user))
		{
			if (it_c->isMode(mode[1]) == 2)
				sendErrorMessage(user._fd, (mode + MODE_ERR_M), ERR_UNKNOWNMODE);
			else
					it_c->exec_mode(mode, user, arg);
		}
		else
			sendErrorMessage(user._fd, OP_ERR_M, ERR_CHANOPRIVSNEEDED);
	}
}

void Command::part(std::string channel, User user)
{
	std::vector<Channel>::iterator it_c;
	std::vector<User>::iterator it_u;

	it_c = chan_exist(channel);
	if (it_c == Server::_channels.end())
		sendErrorMessage(user._fd, (channel + NO_CHAN_M), ERR_NOSUCHCHANNEL);
	
	else
	{
		it_u = it_c->user_in_chan(user._fd);
		if (it_u != it_c->users.end())
		{
			send(user._fd, ("You left the channel " + it_c->getName() + " \n").c_str(),
				strlen(("You left the channel " + it_c->getName() + " \n").c_str()), 0);
			it_c->users.erase(it_u);
			it_u = it_c->op_in_chan(user._fd);
			if (it_u != it_c->operators.end())
				it_c->operators.erase(it_u);
			it_u = it_c->users.begin();
			if (it_u != it_c->users.end() && it_c->operators.size() == 0)
				it_c->operators.push_back(*it_u);
		}
		else
			sendErrorMessage(user._fd, (channel + NOT_USER_M), ERR_NOTONCHANNEL);
	}
}