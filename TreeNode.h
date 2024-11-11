#ifndef TREENODE_H
#define TREENODE_H
#include <string>
#include <vector>

#include "Station.h"

using namespace std;

	class TreeNode{
		public:
		vector<TreeNode*> getChildren() const;
		void setChildren(vector<TreeNode*> inChildren);
		int getNumChildren() const;
		void setChild(int pos, TreeNode* T);
		TreeNode* getChild(int stationNumber) const;
		void setStation(Station* newStation);
		Station* getStation() const;
		bool isLeaf();
		vector<TreeNode*> getLeaves(TreeNode* root, vector<TreeNode*>& leaves) const;

	private:
		Station* station; 
		vector<TreeNode*> children;
	};

#endif