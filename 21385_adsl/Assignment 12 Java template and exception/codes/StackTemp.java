import java.util.Scanner;

abstract class Stack
{
    private Scanner obj;
    
    public final void function()
    {
        int flag=0, op;
        
		obj = new Scanner(System.in);
        
		while(flag!=1)
        {
            System.out.println("\n\n1.Push Element \n2.Pop Element \n3.Display Element at the Top \n4.Exit ");
			
			System.out.print("\n\nEnter Your Choice : ");
            op = obj.nextInt();
            
			switch(op)
            {
                case 1:
					System.out.print("\n\nEnter the Element to be Pushed in Stack : ");
                    push();
                    break;
                
				case 2:
                    pop();
                    break;
                
				case 3:
                    top();
                    break;
                
				case 4:
                    flag=1;
                    break;
                
				default:
                    System.out.println("\n\nEnter the Valid Option...");
                    break;
            }
        }
    }
    abstract protected void push();
    abstract protected void pop();
    abstract protected void top();
}


class IntStack extends Stack
{
	int[] stack1 = new int[15];
	
	int data;
	
    int top = -1;
	
    private Scanner obj;
	
	protected void push()
    {
        obj = new Scanner(System.in);
		
        int x = obj.nextInt();
        
		try
        {
            RuntimeException re= new RuntimeException("\n\nOverflow Occurred...");
			
            if(top==9)
            {
                throw re;
            }
            else
            {
				top++;
                stack1[top] = x;
            }
        }
        catch(RuntimeException ret)
        {
            System.out.println("\n\nException Caught : " + ret);
        }
    }
	
    protected void pop()
    {
        RuntimeException re= new RuntimeException("\n\nUnderflow Occured...");
        
		try
        {
            if(top==-1)
            {
                throw re;
            }
            else
            {
				data = stack1[top];
				top--;
					
				if(data != 0)
                {
                    System.out.println(data + " is Popped...");
                }
            }
        }
        catch(RuntimeException ret)
        {
            System.out.println("\n\nException Caught : " + ret);
        }
    }
	
    protected void top()
    {
        RuntimeException re= new RuntimeException("\n\nUnderflow Occured...");
        try
        {
            if(top == -1)
            {
                throw re;
            }
            else
            {
				data = stack1[top];
				if(data != 0)
                {
                    System.out.println(data + " is at the Top");
                }
			}
        }
        catch(RuntimeException ret)
        {
            System.out.println("\n\nException Caught : " + ret);
        }
    }
    
}

class CharStack extends Stack
{
    char[] stack2 = new char[15];
	
	int top = -1;
	
	char data;
    
	private Scanner obj;
	
	    protected void push()
    {
        obj = new Scanner(System.in);
        
		char x = obj.next().charAt(0);
        
		try
        {
            RuntimeException re= new RuntimeException("\n\nOverflow occured...");
            if(top==9)
            {
                throw re;
            }
            else
            {
				top++;
                stack2[top]=x;
            }
        }
        catch(RuntimeException ret)
        {
            System.out.println("\n\nException Caught : " + ret);
        }
    }
	

    protected void pop()
    {
        RuntimeException re= new RuntimeException("\n\nUnderflow Occurred...");
        try
        {
            if(top==-1)
            {
                throw re;
            }
            else
            {
				data = stack2[top];
				top--;
					
				if(data != '\0')
                {
                    System.out.println(data + " is Popped...");
                }
            }
        }
        catch(RuntimeException ret)
        {
            System.out.println("\n\nException Caught : "+ret);
        }
    }
    protected void top()
    {
        RuntimeException re= new RuntimeException("\n\nUnderflow occured...");
        try
        {
            if(top==-1)
            {
                throw re;
            }
            else
            {
				data = stack2[top];
				if(data != '\0')
                {
                    System.out.println(data + " is at the Top");
                }
            }
        }
        catch(RuntimeException ret)
        {
            System.out.println("\n\nException Caught : "+ret);
        }
    }

}

class StackTemp {

    public static void main(String[] args)
    {
		int ch;
		do
		{
			System.out.println("\n\n----- MENU -----");
			System.out.println("1. Integer Stack");
			System.out.println("2. Character Stack");
			System.out.println("3. Exit");
			
			System.out.print("\n\nEnter Your Choice : ");
			Scanner scan = new Scanner(System.in);
			ch = scan.nextInt();
			
			Stack t;
			
			switch(ch)
			{
				case 1:
					System.out.println("\n\n----- Integer Stack -----");
					t = new IntStack();
					t.function();
					break;
				case 2:
					System.out.println("\n\n----- Character Stack -----");
					t = new CharStack();
					t.function();
					break;
				case 3:
					break;
				default:
					System.out.println("\n\nPlease... Enter the Valid Choice...");
			}
		}while(ch!=3);
	}
}