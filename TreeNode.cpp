#include "treenode.h"
#include <string>
#include <vector>

using namespace std;

	// getters and setters for treenode class
	vector<TreeNode*> TreeNode::getChildren() const{
		return children;
	}
	
	void TreeNode::setChildren(vector<TreeNode*> inChildren) {
		children = inChildren;
	}
	
	int TreeNode::getNumChildren() const{
	  return children.size();
	}

	void TreeNode::setChild(int pos, TreeNode* T){
	  children[pos] = T;
	}
	
	TreeNode* TreeNode::getChild(int stationNumber) const{
	  return children[stationNumber];
	}

	void TreeNode::setStation(Station* newStation){
	  station = newStation;
	}

	Station* TreeNode::getStation() const{
	  return station;
	}

	bool TreeNode::isLeaf() {
		return children.empty(); //returns true if children is empty, false otherwise (a TreeNode is a leaf if it has no children)
	}

	vector<TreeNode*> TreeNode::getLeaves(TreeNode* root, vector<TreeNode*>& leaves) const { //leaves is initially empty
		if(root->getChildren().empty()) //root is a leaf
			leaves.push_back(root); 
		else {
			for(TreeNode* child : root->getChildren()) {
				getLeaves(child, leaves);
			}
		}
		
	  return leaves;
	}