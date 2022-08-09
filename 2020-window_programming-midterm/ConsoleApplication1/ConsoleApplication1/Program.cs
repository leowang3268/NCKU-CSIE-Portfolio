using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1
{
    class Program
    {
        //考後檢討: Console.WriteLine()會直接再寫一行，要用Console.Write("\r\n")
        static void Main(string[] args)
        {
            string[] text_one = new string[9]
{
                "     ",
                "    *",
                "    *",
                "    *",
                "     ",
                "    *",
                "    *",
                "    *",
                "     ",
};
            string[] text_two = new string[9]
            {
                " *** ",
                "    *",
                "    *",
                "    *",
                " *** ",
                "*    ",
                "*    ",
                "*    ",
                " *** ",
            };
            string[] text_three = new string[9]
            {
                " *** ",
                "    *",
                "    *",
                "    *",
                " *** ",
                "    *",
                "    *",
                "    *",
                " *** ",
            };
            string[] text_four = new string[9]
            {
                "     ",
                "*   *",
                "*   *",
                "*   *",
                " *** ",
                "    *",
                "    *",
                "    *",
                "     ",
            };
            string[] text_five = new string[9]
            {
                " *** ",
                "*    ",
                "*    ",
                "*    ",
                " *** ",
                "    *",
                "    *",
                "    *",
                " *** ",
            };
            string[] text_six = new string[9]
            {
                " *** ",
                "*    ",
                "*    ",
                "*    ",
                " *** ",
                "*   *",
                "*   *",
                "*   *",
                " *** ",
            };
            string[] text_seven = new string[9]
            {
                " *** ",
                "    *",
                "    *",
                "    *",
                "     ",
                "    *",
                "    *",
                "    *",
                "     ",
            };
            string[] text_eight = new string[9]
            {
                " *** ",
                "*   *",
                "*   *",
                "*   *",
                " *** ",
                "*   *",
                "*   *",
                "*   *",
                " *** ",
            };
            string[] text_nine = new string[9]
            {
                " *** ",
                "*   *",
                "*   *",
                "*   *",
                " *** ",
                "    *",
                "    *",
                "    *",
                " *** ",
            };
            string[] text_zero = new string[9]
            {
                " *** ",
                "*   *",
                "*   *",
                "*   *",
                "     ",
                "*   *",
                "*   *",
                "*   *",
                " *** ",
            };

            while (true)
            {
                Console.WriteLine("Please input number(0-99):");
                int input = Convert.ToInt32(Console.ReadLine());
                int ten_digit = input / 10, one_digit = input % 10;
                switch (ten_digit)
                {
                    case (0):
                        for(int i=0; i<9; i++)
                        {
                            Console.Write(text_zero[i]);

                            Console.Write("  ");
                            switch (one_digit)
                            {
                                case (0):

                                        Console.Write(text_zero[i]);

                                        Console.Write("  ");

                                        Console.WriteLine();

                                    break;
                                case (1):

                                        Console.Write(text_one[i]);

                                        Console.Write("  ");

                                        Console.WriteLine();
                                    
                                    break;
                                case (2):

                                        Console.Write(text_two[i]);

                                        Console.Write("  ");

                                        Console.WriteLine();

                                    break;
                                case (3):

                                        Console.Write(text_three[i]);

                                        Console.Write("  ");

                                        Console.WriteLine();
                                    
                                    break;
                                case (4):

                                        Console.Write(text_four[i]);

                                        Console.Write("  ");
                                        Console.WriteLine();
                                    
                                    break;
                                case (5):

                                        Console.Write(text_five[i]);

                                        Console.Write("  ");

                                        Console.WriteLine();
                                    
                                    break;
                                case (6):
                                    
                                        Console.Write(text_six[i]);

                                        Console.Write("  ");

                                        Console.WriteLine();
                                    
                                    break;
                                case (7):
                                    
                                        Console.Write(text_seven[i]);

                                        Console.Write("  ");

                                        Console.WriteLine();
                                    
                                    break;
                                case (8):
                                   
                                        Console.Write(text_eight[i]);

                                        Console.Write("  ");

                                        Console.WriteLine();
                                    
                                    break;
                                case (9):
                                    
                                        Console.Write(text_nine[i]);

                                        Console.Write("  ");

                                        Console.WriteLine();
                                    
                                    break;
                            }

                            Console.WriteLine();
                        }
                        break;
                    case (1):
                        for (int i = 0; i < 9; i++)
                        {
                            Console.Write(text_one[i]);

                            Console.Write("  ");
                            switch (one_digit)
                            {
                                case (0):

                                    Console.Write(text_zero[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (1):

                                    Console.Write(text_one[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (2):

                                    Console.Write(text_two[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (3):

                                    Console.Write(text_three[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (4):

                                    Console.Write(text_four[i]);

                                    Console.Write("  ");
                                    Console.WriteLine();

                                    break;
                                case (5):

                                    Console.Write(text_five[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (6):

                                    Console.Write(text_six[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (7):

                                    Console.Write(text_seven[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (8):

                                    Console.Write(text_eight[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (9):

                                    Console.Write(text_nine[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                            }
                            Console.WriteLine();
                        }
                        break;
                    case (2):
                        for (int i = 0; i < 9; i++)
                        {
                            Console.Write(text_two[i]);

                            Console.Write("  ");
                            switch (one_digit)
                            {
                                case (0):

                                    Console.Write(text_zero[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (1):

                                    Console.Write(text_one[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (2):

                                    Console.Write(text_two[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (3):

                                    Console.Write(text_three[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (4):

                                    Console.Write(text_four[i]);

                                    Console.Write("  ");
                                    Console.WriteLine();

                                    break;
                                case (5):

                                    Console.Write(text_five[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (6):

                                    Console.Write(text_six[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (7):

                                    Console.Write(text_seven[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (8):

                                    Console.Write(text_eight[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (9):

                                    Console.Write(text_nine[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                            }
                            Console.WriteLine();
                        }
                        break;
                    case (3):
                        for (int i = 0; i < 9; i++)
                        {
                            Console.Write(text_three[i]);

                            Console.Write("  ");
                            switch (one_digit)
                            {
                                case (0):

                                    Console.Write(text_zero[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (1):

                                    Console.Write(text_one[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (2):

                                    Console.Write(text_two[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (3):

                                    Console.Write(text_three[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (4):

                                    Console.Write(text_four[i]);

                                    Console.Write("  ");
                                    Console.WriteLine();

                                    break;
                                case (5):

                                    Console.Write(text_five[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (6):

                                    Console.Write(text_six[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (7):

                                    Console.Write(text_seven[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (8):

                                    Console.Write(text_eight[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (9):

                                    Console.Write(text_nine[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                            }
                            Console.WriteLine();
                        }
                        break;
                    case (4):
                        for (int i = 0; i < 9; i++)
                        {
                            Console.Write(text_four[i]);

                            Console.Write("  ");
                            switch (one_digit)
                            {
                                case (0):

                                    Console.Write(text_zero[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (1):

                                    Console.Write(text_one[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (2):

                                    Console.Write(text_two[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (3):

                                    Console.Write(text_three[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (4):

                                    Console.Write(text_four[i]);

                                    Console.Write("  ");
                                    Console.WriteLine();

                                    break;
                                case (5):

                                    Console.Write(text_five[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (6):

                                    Console.Write(text_six[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (7):

                                    Console.Write(text_seven[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (8):

                                    Console.Write(text_eight[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (9):

                                    Console.Write(text_nine[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                            }
                            Console.WriteLine();
                        }
                        break;
                    case (5):
                        for (int i = 0; i < 9; i++)
                        {
                            Console.Write(text_five[i]);

                            Console.Write("  ");
                            switch (one_digit)
                            {
                                case (0):

                                    Console.Write(text_zero[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (1):

                                    Console.Write(text_one[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (2):

                                    Console.Write(text_two[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (3):

                                    Console.Write(text_three[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (4):

                                    Console.Write(text_four[i]);

                                    Console.Write("  ");
                                    Console.WriteLine();

                                    break;
                                case (5):

                                    Console.Write(text_five[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (6):

                                    Console.Write(text_six[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (7):

                                    Console.Write(text_seven[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (8):

                                    Console.Write(text_eight[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (9):

                                    Console.Write(text_nine[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                            }
                            Console.WriteLine();
                        }
                        break;
                    case (6):
                        for (int i = 0; i < 9; i++)
                        {
                            Console.Write(text_six[i]);

                            Console.Write("  ");
                            switch (one_digit)
                            {
                                case (0):

                                    Console.Write(text_zero[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (1):

                                    Console.Write(text_one[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (2):

                                    Console.Write(text_two[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (3):

                                    Console.Write(text_three[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (4):

                                    Console.Write(text_four[i]);

                                    Console.Write("  ");
                                    Console.WriteLine();

                                    break;
                                case (5):

                                    Console.Write(text_five[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (6):

                                    Console.Write(text_six[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (7):

                                    Console.Write(text_seven[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (8):

                                    Console.Write(text_eight[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (9):

                                    Console.Write(text_nine[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                            }
                            Console.WriteLine();
                        }
                        break;
                    case (7):
                        for (int i = 0; i < 9; i++)
                        {
                            Console.Write(text_seven[i]);

                            Console.Write("  ");
                            switch (one_digit)
                            {
                                case (0):

                                    Console.Write(text_zero[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (1):

                                    Console.Write(text_one[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (2):

                                    Console.Write(text_two[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (3):

                                    Console.Write(text_three[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (4):

                                    Console.Write(text_four[i]);

                                    Console.Write("  ");
                                    Console.WriteLine();

                                    break;
                                case (5):

                                    Console.Write(text_five[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (6):

                                    Console.Write(text_six[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (7):

                                    Console.Write(text_seven[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (8):

                                    Console.Write(text_eight[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (9):

                                    Console.Write(text_nine[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                            }
                            Console.WriteLine();
                        }
                        break;
                    case (8):
                        for (int i = 0; i < 9; i++)
                        {
                            Console.Write(text_eight[i]);

                            Console.Write("  ");
                            switch (one_digit)
                            {
                                case (0):

                                    Console.Write(text_zero[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (1):

                                    Console.Write(text_one[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (2):

                                    Console.Write(text_two[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (3):

                                    Console.Write(text_three[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (4):

                                    Console.Write(text_four[i]);

                                    Console.Write("  ");
                                    Console.WriteLine();

                                    break;
                                case (5):

                                    Console.Write(text_five[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (6):

                                    Console.Write(text_six[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (7):

                                    Console.Write(text_seven[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (8):

                                    Console.Write(text_eight[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (9):

                                    Console.Write(text_nine[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                            }
                            Console.WriteLine();
                        }
                        break;
                    case (9):
                        for (int i = 0; i < 9; i++)
                        {
                            Console.Write(text_nine[i]);

                            Console.Write("  ");
                            switch (one_digit)
                            {
                                case (0):

                                    Console.Write(text_zero[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (1):

                                    Console.Write(text_one[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (2):

                                    Console.Write(text_two[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (3):

                                    Console.Write(text_three[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (4):

                                    Console.Write(text_four[i]);

                                    Console.Write("  ");
                                    Console.WriteLine();

                                    break;
                                case (5):

                                    Console.Write(text_five[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (6):

                                    Console.Write(text_six[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (7):

                                    Console.Write(text_seven[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (8):

                                    Console.Write(text_eight[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                                case (9):

                                    Console.Write(text_nine[i]);

                                    Console.Write("  ");

                                    Console.WriteLine();

                                    break;
                            }
                            Console.WriteLine();
                        }
                        break;
                }
                
            }
        }
    }
}
