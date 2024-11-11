#include "treenode.h"
#include <string>
#include <vector>

using namespace std;

	//Constructors
	//Explicit constructor 
	TreeNode::TreeNode(Station* inStation, vector<TreeNode> inChildren) {
		station = inStation;
		children = inChildren;
	}
	
	//Default constructor
	TreeNode::TreeNode() {
		
	}

	//Getters
	vector<TreeNode> TreeNode::getChildren() const{
		return children;
	}
	
	int TreeNode::getNumChildren() const{
	  return children.size();
	}

	TreeNode TreeNode::getChild(int stationNumber) const{
	  return children[stationNumber];
	}
	
		Station* TreeNode::getStation() const{
	  return station;
	}
	
	void TreeNode::getLeaves(TreeNode root, vector<TreeNode>& leaves) const { //leaves is initially empty
		if(root.isLeaf()) //root is a leaf
			leaves.push_back(root); 
		else {
			for(TreeNode child : root.getChildren()) {
				getLeaves(child, leaves);
			}
		}

	}
	
	
	//Setters
		void TreeNode::setChildren(vector<TreeNode> inChildren) {
		children = inChildren;
	}
	
		void TreeNode::setChild(int pos, TreeNode T){
	  children[pos] = T;
	}
	
	void TreeNode::setStation(Station* newStation){
	  station = newStation;
	}

	
	//Other functions
	bool TreeNode::isLeaf() {
		return children.empty(); //returns true if children is empty, false otherwise (a TreeNode is a leaf if it has no children)
	}

	