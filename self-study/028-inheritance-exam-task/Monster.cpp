#include "Monster.hpp"

const Monster::MonsterData Monster::monsterData[Monster::Type::MAX_TYPES]
{
	{"dragon", 'D', 20, 4, 100},
	{"orc", 'o', 4, 2, 25},
	{"slime", 's', 1, 1, 10}
};
