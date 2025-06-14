#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter {
	private:
		std::string name;
		AMateria *inventory[4];
	public:
		Character();
		Character(const Character& other);
		Character& operator=(const Character& other);
		~Character();

		Character(std::string const & name);

		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif