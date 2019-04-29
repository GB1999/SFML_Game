#pragma once
#include "Room.h"
#include <vector>
using namespace std;

class gameGraph
{
private:
	class vertex
	{
	public:
		 Room data;

		//List of all edges leaving this vertex
		vector<vertex*> neighbors;

		vertex(Room x)
		{
			data = x;
		}
	};

	//For faster vertex lookups,
	//Replace this with a binary search tree (or hash table)
	vector<vertex*> vertexList;

	//Return the vertex with x as it's data field.
	//Return null if it doesn't exist.
	//O( n )  -- oooh slow, use a bst to make this faster 
	vertex * findVertex(Room x)
	{
		for (int i = 0; i < vertexList.size(); i++)
		{
			if (vertexList[i]->data == x)
				return vertexList[i];
		}
		return nullptr;
	}

	///////////Game specific stuff////////////////
	vertex * playerLocation;


public:

	void addVertex(Room x)
	{
		vertex * babyVertex = new vertex(x);
		vertexList.push_back(babyVertex);
	}

	void addDirectedEdge(Room x, Room y)
	{
		vertex * xVert = findVertex(x);
		vertex * yVert = findVertex(y);

		if (xVert == nullptr || yVert == nullptr)
		{
			cout << "Oh no!  You've hosed up!" << endl;
		}
		else
		{
			xVert->neighbors.push_back(yVert);
		}
	}

	void addEdge(Room x, Room y)
	{
		addDirectedEdge(x, y);
		addDirectedEdge(y, x);
	}

	/////////////Game specific methods///////////////

	void setPlayerLocation(Room x)
	{
		playerLocation = findVertex(x);
	}

	Room getPlayerLocation()
	{
		return playerLocation->data;
	}

}; 
