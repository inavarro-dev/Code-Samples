using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Binary_Tree
{
    class Node
    {
        private Node parent;
        private Node left;
        private Node right;
        private int depth;
        private int index;

        //constructor
        public Node(Node parent,int depth, int index)
        {
            this.parent = parent;
            this.depth = depth;
            this.left = null;
            this.right = null;
            this.index = index;

        }

        //set functions
        public void addLeftChild(Node leftNode)
        {
            left = leftNode;


        }
        public void addRightChild(Node rightNode)
        {
            right = rightNode;


        }

        //get functions
        public Node getLeft()
        {
            return left;
        }
        public Node getRight()
        {
            return right;
        }
        public Node getParent()
        {
            return parent;
        }
        public int getIndex()
        {
            return index;
        }
        public int getDepth()
        {
            return depth;
        }
        
    }

    class Tree
    {
        public Node rootNode;
        private int totalDepth = 0;
        private static bool right = true;
        private static bool left = false;
        public List<Node> NodeList =new List<Node>();
        public int indexCount = 0;

        //representing right and left as true or false respectively

        public Tree()
        {
            rootNode = new Node(null, 0, indexCount);
            NodeList.Add(rootNode);
            Console.WriteLine("\nNODE CREATED AT INDEX " + rootNode.getIndex());
        }

        //uses direction bool variable upon creation of new node.
        public void createNewNode(Node parent, int depth, bool direction)
        {

           
            indexCount++;

            if(direction == right)
            {
                Node tempNode = new Node(parent, depth, indexCount);
                parent.addRightChild(tempNode);
                NodeList.Add(tempNode);
                if(tempNode.getDepth() > totalDepth)
                {
                    totalDepth = depth;
                }
                Console.WriteLine("\nNODE CREATED AT INDEX " + tempNode.getIndex());
            }

            if(direction == left)
            {
                Node tempNode = new Node(parent, depth, indexCount);
                parent.addLeftChild(tempNode);
                NodeList.Add(tempNode);
                if (tempNode.getDepth() > totalDepth)
                {
                    totalDepth = depth;
                }
                Console.WriteLine("\nNODE CREATED AT INDEX " + tempNode.getIndex());
            }         
        }

        public Node search(int index)
        {
            foreach (Node i in NodeList)
            {
                int check;
                check = i.getIndex();
                if (index == check)
                {
                    return i;
                }

            }
            Console.WriteLine("\nNode was not found.\n");
            return null;
        }

        public bool isFull()
        {
            bool noChildrenAtBottom = false;
            bool noHoles = false;

            foreach (Node i in NodeList)
            {
                if(totalDepth==0)
                {
                    return true;
                }
                if(i.getDepth() == totalDepth)
                {
                    if (i.getLeft() == null && i.getRight() == null)
                    {
                        noChildrenAtBottom = true;
                    }
                }
                
                if(i.getDepth() < totalDepth)
                {
                    if (i.getLeft() != null && i.getRight() != null)
                    {
                        noHoles = true;
                    }

                }
            }
            if (noChildrenAtBottom == true && noHoles == true)
            {
                return true;
            }
            else
            {
                return false;
            }

        }

        public bool isComplete(Node node)
        {
            int flag = 0;

            if(node.getDepth() == totalDepth -1)
            {
                if ((node.getLeft() == null || node.getRight() == null) && flag == 0)
                    flag++;
                if ((node.getLeft() != null || node.getRight() != null) && flag == 1)
                    flag++;
            }
            if (node.getLeft() != null)
            {
                postorder(node.getLeft());

            }
            if (node.getRight() != null)
            {
                postorder(node.getRight());
            }

            if (flag > 1)
            {
                return false;
            }
            else
            {
                return true;
            }

        }

        public int nodeCount()
        {
            return indexCount +1;
        }

        public int treeDepth()
        {
            return totalDepth + 1;
        }

        public void preorder(Node node)
        {
            if(node !=null)
            {
                Console.Write(node.getIndex());
                preorder(node.getLeft());
                preorder(node.getRight());
            }


        }

        public void inorder(Node node)
        {

            if (node != null)
            {
                inorder(node.getLeft());
                Console.Write(node.getIndex());
                inorder(node.getRight());
            }


        }
        public void postorder(Node node)
        {
            if (node.getLeft() != null)
            {
                postorder(node.getLeft());

            }
            if (node.getRight() != null)
            {
                postorder(node.getRight());
            }
            Console.Write(node.getIndex());

        }

    }

    class Program
    {
        static void Main(string[] args)
        {
            int index;
            bool right = true;
            bool left = false;
            char exit;
            Node currentNode;

        Tree binaryTree = new Tree();

            Console.WriteLine("Root node created at index 0");

            do
            {
                Console.WriteLine("There are {0} nodes in the tree.\n" , binaryTree.nodeCount());
                Console.WriteLine("The tree is {0} levels deep.\n", binaryTree.treeDepth());
                if (binaryTree.isFull())
                {
                    Console.WriteLine("This binary tree is full\n");
                }
                else
                {
                    Console.WriteLine("This binary tree is not full\n");
                }

                if (binaryTree.isComplete(binaryTree.rootNode))
                {
                    Console.WriteLine("This binary tree is complete\n");
                }
                else
                {
                    Console.WriteLine("This binary tree is not complete\n");
                }

                Console.WriteLine("\npreorder: ");
                binaryTree.preorder(binaryTree.rootNode);
                Console.WriteLine("\ninorder: ");
                binaryTree.inorder(binaryTree.rootNode);
                Console.WriteLine("\npostorder: ");
                binaryTree.postorder(binaryTree.rootNode);




                Console.WriteLine("\nPlease select an index to add a child to.");
                index = Convert.ToInt32(Console.ReadLine());

                currentNode = binaryTree.search(index);

                if (currentNode != null)
                {

                    Console.WriteLine("\nWhich side would you like to place new child on? (enter r for right l for left)\n");
                    char dirSelection = Console.ReadKey().KeyChar;
                    if (dirSelection == 'r')
                    {
                        if (currentNode.getRight() == null)
                        {
                            binaryTree.createNewNode(currentNode, currentNode.getDepth() +1, right);
                        }
                        else
                        {
                            Console.WriteLine("A node already exists at this location, please try another location.\n");
                        }
                    }

                    if (dirSelection == 'l')
                    {
                        if (currentNode.getLeft() == null)
                        {
                            binaryTree.createNewNode(currentNode, currentNode.getDepth(), left);
                        }
                        else
                        {
                            Console.WriteLine("A node already exists at this location, please try another location.\n");
                        }

                    }
                }
                
                Console.WriteLine("Press y to exit or any other key to continue.\n");
                exit = Console.ReadKey().KeyChar;
                Console.WriteLine("\n\n");
                Console.Clear();

            } while (exit != 'y');




        }
    }
}
