import myPackage.personalDetails;
import myPackage.officialDetails;

import java.util.Scanner;

public class Employee implements personalDetails, officialDetails
{
	int eid, age;
	String name, addr, desig;
	
	public void getName(String name)
	{
		this.name=name;
	}
	
	public void getAge(int age)
	{
		this.age=age;
	}
	
	public void getAddress(String addr)
	{
		this.addr=addr;
	}
	
	public void getEmpId(int eid)
	{
		this.eid = eid;
	}

	public void getDesig(String desig)
	{
		this.desig = desig;
	}
	
	
	public void showName()
	{
		System.out.println("Name		: "+name);
	}
	
	public void showAge()
	{
		System.out.println("Age		: "+age);
	}
	
	public void showAddress()
	{
		System.out.println("Address		: "+addr);
	}
	
	public void showEmpId()
	{
		System.out.println("Employee ID	: "+eid);
	}

	public void showDesig()
	{
		System.out.println("Designation	: "+desig);
	}
	
	
	public static void main(String args[])
	{
		Employee emp = new Employee();
		int ch, n;
		
		do
		{
			System.out.println("\n\n----------------MENU----------------");
			System.out.println("1. Enter Employee Information");
			System.out.println("2. Display Employee Information");
			System.out.println("3. Exit");
			
			Scanner scan1 = new Scanner(System.in);
			Scanner scan2 = new Scanner(System.in);
			
			System.out.print("\n\nEnter Your Choice : ");
			ch = scan2.nextInt();
			
			switch(ch)
			{
				case 1:
					String nm, adr, dsg;
					int a, id;
					
					System.out.print("\n\nEnter Name : ");
					nm = scan1.nextLine();
					
					System.out.print("Enter Age : ");
					a = scan2.nextInt();
					
					System.out.print("Enter Address : ");
					adr = scan1.nextLine();
					
					System.out.print("Enter Employee ID : ");
					id = scan2.nextInt();
					
					System.out.print("Enter Designation : ");
					dsg = scan1.nextLine();
					
					emp.getName(nm);
					emp.getAge(a);
					emp.getAddress(adr);
					emp.getEmpId(id);
					emp.getDesig(dsg);
					
					break;
					
				case 2:
					System.out.println("\n\n--------- Employee Details ---------");
					emp.showName();
					emp.showAge();
					emp.showAddress();
					emp.showEmpId();
					emp.showDesig();
					
					break;
					
				case 3:
					break;
					
				default:
					System.out.println("Please... Enter the Valid Choice...");
					break;
			}
		}while(ch!=3)	;
		
	}	
}