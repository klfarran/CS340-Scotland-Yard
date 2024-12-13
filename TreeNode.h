#ifndef TREENODE_H
#define TREENODE_H
#include <string>
#include <vector>


using namespace std;

	class TreeNode{
		public:
		
		//Constructor
		TreeNode(int station, vector<TreeNode> children);
		TreeNode();
		
		//Getters
		vector<TreeNode> getChildren() const;
		int getNumChildren() const;
		TreeNode getChild(int stationNumber) const;
		int getStation() const;
		void getLeaves(TreeNode root, vector<TreeNode>& leaves) const;
		
		//Setters
		void setChildren(vector<TreeNode> inChildren);
		void setChild(int pos, TreeNode T);	
		void setStation(int newStation);

		//Other Functions
		bool isLeaf();
		void printNode();
		
 
	private:
		int station; 
		vector<TreeNode> children;
	};

#endif