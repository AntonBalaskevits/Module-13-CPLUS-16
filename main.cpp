#include "graph.h"

int main()
{
	Graph friends;

	friends.addVertexName(0, "Oleg");
	friends.addVertexName(1, "Nikita");
	friends.addVertexName(2, "Nastja");
	friends.addVertexName(3, "Vanja");
	friends.addVertexName(4, "Zenja");

	friends.addBondByName("Oleg", "Nikita"); // 01 edge
	friends.addBondByName("Oleg", "Nastja"); // 02
	friends.addBondByName("Oleg", "Vanja"); // 03
	friends.addBondByName("Nikita", "Nastja"); // 12
	friends.addBondByName("Nikita", "Vanja"); // 13
	friends.addBondByName("Nikita", "Zenja"); // 14
	friends.addBondByName("Nastja", "Vanja"); // 23
	friends.addBondByName("Nastja", "Zenja"); // 24
	friends.addBondByName("Nastja", "Oleg"); // 20
	friends.addBondByName("Vanja", "Oleg"); // 30
	friends.addBondByName("Vanja", "Nikita"); // 31
	friends.addBondByName("Vanja", "Zenja"); // 34
	friends.addBondByName("Zenja", "Nastja"); // 42
	friends.addBondByName("Zenja", "Nikita"); // 41
	friends.addBondByName("Zenja", "Vanja"); // 43

	friends.checkBonds();

	return 0;
}