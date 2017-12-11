using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Assignment_13
{
    
    class Tower
    {

        public string name;
        public Stack<int> discs = new Stack<int>();


        public Tower(string name,int numOfDiscs)
        {
           this.name = name;

            for(int i = numOfDiscs; i> 0; i--)
            {
                discs.Push(i);
            }

            
        }
        


    }

    class Program
    {
        static void Main(string[] args)
        {
            int num;
            Console.WriteLine("How many discs would you like to solve for?\n");
            num = Convert.ToInt32(Console.ReadLine());

            Tower towerA = new Tower("A", num);
            Tower towerB = new Tower("B", 0);
            Tower towerC = new Tower("C", 0);

            
            towerOfHanoi( num ,towerA, towerC,towerB);
            
        }

        static void towerOfHanoi(int n, Tower fromTower, Tower toTower, Tower midTower)
        {
            if (n == 1)
            {
                toTower.discs.Push(fromTower.discs.Pop());
                Console.WriteLine("Move disk 1 from tower " + fromTower.name + " to tower " + toTower.name + "\n");
                printDiscPos(n, fromTower, midTower, toTower);
                Console.ReadKey();
                return;
            }
            towerOfHanoi(n - 1, fromTower, midTower, toTower);
            toTower.discs.Push(fromTower.discs.Pop());
            Console.WriteLine("Move disk " + n + " from tower " + fromTower.name + " to tower " + toTower.name + "\n");
            printDiscPos(n, fromTower, toTower, midTower);
            Console.ReadKey();
            towerOfHanoi(n - 1, midTower, toTower, fromTower);
        }

        static void printDiscPos(int n, Tower fromTower, Tower toTower, Tower midTower)
        {
            Stack<int> TTowerA = new Stack<int>();
            Stack<int> TTowerB = new Stack<int>();
            Stack<int> TTowerC = new Stack<int>();

            int sizeA = fromTower.discs.Count();
            int sizeB = toTower.discs.Count();
            int sizeC = midTower.discs.Count();
            //Print A
            {//findA
                if (fromTower.name == "A")
                {
                    Console.Write("\nTower {0}", fromTower.name);
                    for (int i = 0; i < sizeA; i++)
                    {
                        TTowerA.Push(fromTower.discs.Pop());


                    }
                    for (int i = 0; i < sizeA; i++)
                    {
                        fromTower.discs.Push(TTowerA.Pop());
                        Console.Write(fromTower.discs.Peek());

                    }
                }

                if (toTower.name == "A")
                {

                    Console.Write("\nTower {0}", toTower.name);
                    for (int i = 0; i < sizeB; i++)
                    {
                        TTowerB.Push(toTower.discs.Pop());


                    }
                    for (int i = 0; i < sizeB; i++)
                    {
                        toTower.discs.Push(TTowerB.Pop());
                        Console.Write(toTower.discs.Peek());

                    }

                }

                if (midTower.name == "A")
                {
                    
                    Console.Write("\nTower {0}", midTower.name);
                    for (int i = 0; i < sizeC; i++)
                    {
                        TTowerC.Push(midTower.discs.Pop());


                    }
                    for (int i = 0; i < sizeC; i++)
                    {
                        midTower.discs.Push(TTowerC.Pop());
                        Console.Write(midTower.discs.Peek());

                    }

                }


            }
            //Print B
            {//findB
                if (fromTower.name == "B")
                {
                    Console.Write("\nTower {0}", fromTower.name);
                    for (int i = 0; i < sizeA; i++)
                    {
                        TTowerA.Push(fromTower.discs.Pop());


                    }
                    for (int i = 0; i < sizeA; i++)
                    {
                        fromTower.discs.Push(TTowerA.Pop());
                        Console.Write(fromTower.discs.Peek());

                    }
                }

                if (toTower.name == "B")
                {

                    Console.Write("\nTower {0}", toTower.name);
                    for (int i = 0; i < sizeB; i++)
                    {
                        TTowerB.Push(toTower.discs.Pop());


                    }
                    for (int i = 0; i < sizeB; i++)
                    {
                        toTower.discs.Push(TTowerB.Pop());
                        Console.Write(toTower.discs.Peek());

                    }

                }

                if (midTower.name == "B")
                {

                    Console.Write("\nTower {0}", midTower.name);
                    for (int i = 0; i < sizeC; i++)
                    {
                        TTowerC.Push(midTower.discs.Pop());


                    }
                    for (int i = 0; i < sizeC; i++)
                    {
                        midTower.discs.Push(TTowerC.Pop());
                        Console.Write(midTower.discs.Peek());

                    }

                }


            }
            //Print C
            {//findC
                if (fromTower.name == "C")
                {
                    Console.Write("\nTower {0}", fromTower.name);
                    for (int i = 0; i < sizeA; i++)
                    {
                        TTowerA.Push(fromTower.discs.Pop());


                    }
                    for (int i = 0; i < sizeA; i++)
                    {
                        fromTower.discs.Push(TTowerA.Pop());
                        Console.Write(fromTower.discs.Peek());

                    }
                }

                if (toTower.name == "C")
                {

                    Console.Write("\nTower {0}", toTower.name);
                    for (int i = 0; i < sizeB; i++)
                    {
                        TTowerB.Push(toTower.discs.Pop());


                    }
                    for (int i = 0; i < sizeB; i++)
                    {
                        toTower.discs.Push(TTowerB.Pop());
                        Console.Write(toTower.discs.Peek());

                    }

                }

                if (midTower.name == "C")
                {

                    Console.Write("\nTower {0}", midTower.name);
                    for (int i = 0; i < sizeC; i++)
                    {
                        TTowerC.Push(midTower.discs.Pop());


                    }
                    for (int i = 0; i < sizeC; i++)
                    {
                        midTower.discs.Push(TTowerC.Pop());
                        Console.Write(midTower.discs.Peek());

                    }

                }


            }
        }

    }
}
