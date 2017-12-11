using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assignment_15
{
    class Program
    {
        static void Main(string[] args)
        {
            List<string> setA = new List<string>();
            List<string> setB = new List<string>();

            string stringToAdd;
            int selection;

            

            

            do
            {
                Console.Clear();
                Console.WriteLine("Please select an option from the list below.(enter 0 to exit)\n\n");
                Console.WriteLine("1.)  Add string to set A\n");
                Console.WriteLine("2.)  Add string to set B\n");
                Console.WriteLine("3.)  A Union B\n");
                Console.WriteLine("4.)  A Intersect B\n");
                Console.WriteLine("5.)  A - B\n\n");
                Console.WriteLine("6.)  B - A\n");
                Console.WriteLine("7.)  A x B\n");
                Console.WriteLine("8.)  Powerset A \n");
                Console.WriteLine("9.)  Powerset B \n");
                Console.WriteLine("10.)  Display all in set A \n");
                Console.WriteLine("11.)  Display all in set B \n");


                selection = Convert.ToInt32(Console.ReadLine());
                switch (selection)
                {
                    case 1:
                        Console.Clear();
                        stringToAdd = AddLine();
                        Console.WriteLine("You entered \n");
                        Console.WriteLine(stringToAdd);
                        setA.Add(stringToAdd);
                        break;

                    case 2:
                        Console.Clear();
                        stringToAdd = AddLine();
                        Console.WriteLine("You entered \n");
                        Console.WriteLine(stringToAdd);
                        setB.Add(stringToAdd);
                        break;

                    case 3:
                        setA.AddRange(setB);
                        Console.WriteLine("Combined set A and B into set A");
                        break;

                    case 4:
                        findIntersect(setA, setB);
                        Console.ReadKey();
                        Console.Clear();
                        break;

                    case 5:
                        findDifference(setA, setB);
                        Console.WriteLine("Removed all items from set A that were also in set B");
                        Console.ReadKey();
                        Console.Clear();
                        break;

                    case 6:
                        findDifference(setB, setA);
                        Console.WriteLine("Removed all items from set B that were also in set A");
                        Console.ReadKey();
                        Console.Clear();
                        break;

                    case 7:
                        showCartProduct(setA, setB);
                        Console.WriteLine("Cartesian product of these two sets is displayed.");
                        Console.ReadKey();
                        Console.Clear();
                        break;

                    case 8:
                        showPowerset(setA);
                        Console.WriteLine("Powerset of setA was displayed.");
                        Console.ReadKey();
                        Console.Clear();
                        break;

                    case 9:
                        showPowerset(setB);
                        Console.WriteLine("Powerset of setB was displayed.");
                        Console.ReadKey();
                        Console.Clear();
                        break;

                    case 10:
                        foreach (var element in setA)
                        {
                            Console.WriteLine(element);
                        }
                        Console.ReadKey();
                        Console.Clear();
                        break;

                    case 11:
                        foreach (var element in setB)
                        {
                            Console.WriteLine(element);
                        }
                        Console.ReadKey();
                        Console.Clear();
                        break;

                }
            } while (selection != 0);

            

        }

        static string AddLine()
        {
            Console.WriteLine("Please enter a string for the selected set.\n");
            string returnString;

            returnString = Console.ReadLine();

            return returnString;
        }

        static void showPowerset(List<string>set)
        {

           
            var result = new List<List<string>>();
            for (int i = 0; i < (1 << set.Count); i++)
            { 
                var sublist = new List<string>();
                for (int j = 0; j < set.Count; j++)
                {   
                    if ((i & (1 << j)) != 0)
                    {
                        sublist.Add(set[j]);
                    }
                }
                result.Add(sublist);
            }

            Console.Write("[");
            foreach(var i in result)
            {
                Console.Write("{");
                foreach (var j in i)
                {
                    Console.Write( j + ",");
                }
                Console.Write("}");
            }
            Console.Write("]");


        }


            static void showCartProduct(List<string>setA, List<string> setB)
        {
            foreach (string i in setA)
            {
                foreach (string j in setA)
                {
                    Console.WriteLine("({0},{1}) ", i, j);
                }

            }

        }

        static void findDifference(List<string> setA,List<string> setB)
        {
            foreach (string i in setA)
            {
                foreach (string j in setA)
                {
                    if (j == i)
                    {
                        setA.Remove(j);

                    }
                }

            }

        }
        static void findIntersect(List<string> setA, List<string> setB)
        {
            List<string> setC = new List<string>();

            foreach (string i in setA)
            {
                foreach (string j in setA)
                {
                    if(j == i)
                    {
                        setC.Add(j);

                    }
                }

            }

            foreach (string itm in setC)
            {
                Console.WriteLine(itm);   
            }

        }

    }
}
