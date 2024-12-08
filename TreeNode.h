#ifndef TREENODE_H
#define TREENODE_H
#include <string>
#include <vector>

#include "Station.h"

using namespace std;

	class TreeNode{
		public:
		
		//Constructor
		TreeNode(Station station, vector<TreeNode> children);
		TreeNode();
		
		//Getters
		vector<TreeNode> getChildren() const;
		int getNumChildren() const;
		TreeNode getChild(int stationNumber) const;
		Station getStation() const;
		void getLeaves(TreeNode root, vector<TreeNode>& leaves) const;
		
		//Setters
		void setChildren(vector<TreeNode> inChildren);
		void setChild(int pos, TreeNode T);	
		void setStation(Station newStation);

		//Other Functions
		bool isLeaf();
		void printNode();
		
 
	private:
		Station station; 
		vector<TreeNode> children;
	};

#endif