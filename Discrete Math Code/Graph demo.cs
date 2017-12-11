using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assignment_17
{


    class Vertex
    {
        public List<Vertex> edges = new List<Vertex>();
        public char index;
        public int degree;

        public Vertex(char index)
        {
            this.index = index;
            degree = 0;

        }



    }

    class Program
    {
        

        static void Main(string[] args)
        {

            List<Vertex> vertexList = new List<Vertex>();

            int selection;
            Vertex currentVertex;
            char indexTracker = 'a';
            do
            {
                Console.Clear();
                Console.WriteLine("Please select an option from the list below.(enter 0 to exit)\n\n");
                findHighestDeg(vertexList);
                findIsolatedVerts(vertexList);
                findLoops(vertexList);
                isGraphConnected(vertexList);
                isGraphComplete(vertexList);
                Console.WriteLine("\n1.)  Create new vertex\n");
                Console.WriteLine("2.)  Create an edge between two vertices or a loop on one vertex\n");



                selection = Convert.ToInt32(Console.ReadLine());
                switch (selection)
                {
                    case 1:
                        Console.Clear();
                        currentVertex = createNewVertex(indexTracker);
                        indexTracker++;
                        vertexList.Add(currentVertex);
                        Console.WriteLine("New vertex {0} created!" , currentVertex.index);
                        Console.ReadKey();
                        Console.Clear();

                        break;

                    case 2:
                        char firstindex;
                        char secondindex;
                        Vertex vert1 = null;
                        Vertex vert2 = null;
                        Console.Clear();
                        Console.WriteLine("Please enter the names of the vertices you'd like to connect.");
                        firstindex = Console.ReadKey().KeyChar;
                        vert1 = findVertex(firstindex,vertexList);
                        if (vert1 == null)
                        {
                            break;
                        }

                        Console.WriteLine("\nenter the name of the second vetex");
                        secondindex = Console.ReadKey().KeyChar;
                        vert2 = findVertex(secondindex, vertexList);
                        if (vert2 == null)
                        {
                            break;
                        }
                        connectVertices(vert1, vert2);
                        Console.WriteLine("\nNew edge created between {0} and {1}!", vert1.index , vert2.index);
                        Console.ReadKey();
                        Console.Clear();
                        break;

                }

            } while (selection != 0);

        }

        static Vertex createNewVertex(char index)
        {
            Vertex newVertex = new Vertex(index);

            return newVertex;
        }

        static Vertex findVertex(char index, List<Vertex> vertList)
        {
            Vertex foundVertex = null;
            foreach(var i in vertList)
            {
                if (index == i.index)
                {
                    foundVertex = i;
                }

            }
            if(foundVertex == null)
            {
                Console.WriteLine("vertex not found, please try again. (press any key to continue)");
                Console.ReadKey();
                return foundVertex;
            }
            return foundVertex;
        }

        static void connectVertices(Vertex vert1, Vertex vert2)
        {
            vert1.edges.Add(vert2);
            vert1.degree++;
            vert2.edges.Add(vert1);
            vert2.degree++;
        }

        static void findHighestDeg(List<Vertex> vertList)
        {
            if (vertList.Count() == 0 )
            {
                Console.WriteLine("\nNo edges have been created\n");
                return;
            }
            int degCount = 0;
            char highName = 'Z';
            foreach(var i in vertList)
            {
                if (i.degree > degCount)
                {
                    degCount = i.degree;
                    highName = i.index;
                }
            }
            if (degCount == 0)
            {
                Console.WriteLine("\nNo edges have been created\n");
                return;
            }

            Console.WriteLine("\nVertex {0} has the highest degree at {1}\n" , highName , degCount);

        }

        static void findIsolatedVerts(List<Vertex> vertList)
        {
            if (vertList.Count() == 0)
            {
                Console.WriteLine("\nNo vertices have been created\n");
                return;
            }

            Console.Write("\n Isolated vertices: ");
            foreach (var i in vertList)
            {
                if (i.degree == 0)
                {
                    Console.Write("{0} ", i.index);
                }
            }
           

        }
        static void findLoops(List<Vertex> vertList)
        {
            if (vertList.Count() == 0)
            {
                Console.Write("\n");
                return;
            }
            int loopCount = 0;
            
            foreach (var i in vertList)
            {
                foreach(var j in i.edges)
                {
                    if(j.index == i.index)
                    {
                        loopCount++;
                    }

                }
            }

            loopCount = loopCount / 2;

            Console.Write("\n There are {0} loops in your graph.\n", loopCount);



        }

        static void isGraphConnected(List<Vertex> vertList)
        {
            if (vertList.Count() == 0)
            {
                Console.Write("\n");
                return;
            }
            if (vertList.Count() == 1)
            {
                Console.WriteLine("\nGraph is connected\n");
                return;
            }

            bool isConnected = true;
            foreach (var i in vertList)
            {
                if (i.degree == 0)
                {
                    isConnected = false;
                    
                }
            }
            if(isConnected == false)
            {
                Console.WriteLine("\nGraph is not connected\n");
            }
            else
            {
                if (isConnected == true)
                {
                    Console.WriteLine("\nGraph is connected\n");
                }
            }


        }

        static Vertex findVertexCompCheck(char index, List<Vertex> vertList)
        {
            Vertex foundVertex = null;
            foreach (var i in vertList)
            {
                if (index == i.index)
                {
                    foundVertex = i;
                }

            }
            if (foundVertex == null)
            {
                return foundVertex;
            }
            return foundVertex;
        }

        static void isGraphComplete(List<Vertex> vertList)
        {
            if (vertList.Count() == 0)
            {
                Console.Write("\n");
                return;
            }
            if (vertList.Count() == 1)
            {
                Console.WriteLine("\nGraph is complete\n");
                return;
            }

            bool isComplete = true;

            foreach (var i in vertList)
            {
                Vertex testVert;
                foreach (var j in vertList)
                {
                    if (j.index == i.index)
                    {

                    }
                    else
                    {
                        testVert = findVertexCompCheck(j.index, i.edges);
                        if (testVert == null)
                        {
                            isComplete = false;
                        }
                    }

                }
               
            }
            if (isComplete == false)
            {
                Console.WriteLine("\nGraph is not complete\n");
            }
            else
            {
                if (isComplete == true)
                {
                    Console.WriteLine("\nGraph is complete\n");
                }
            }


        }



    }
}
