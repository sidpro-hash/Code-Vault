/**
 * 
 */
package javasem6;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;
import org.hibernate.cfg.Configuration;
import org.hibernate.query.Query;

import java.util.List;
import java.util.Scanner;
/**
 * CREATE TABLE emp10000 (
 *  emp_id int PRIMARY KEY,
 *  emp_name varchar(255),
 *  job_name varchar(255),
 *  salary Number(15,2)
 * );
 * 
 * @author Sidpro
 *
 */
public class StoreData {
	public static void main (String[] args) {
	
		
		String job_name="",emp_name="";
		int emp_id=106;
		int salary=50000;
		
		Scanner scan = new Scanner(System.in);
		
		System.out.print("Enter FirstName: ");
		emp_name = scan.nextLine();
		
		System.out.println("1 MANAGER");
		System.out.println("2 SALESMAN");
		System.out.println("3 CLERK");
		System.out.println("4 ANALYST");
		System.out.print("Select your Job 1/2/3/4 ?:");
		int option = scan.nextInt();
		switch(option){
			case 1:job_name="MANAGER";break;
			case 2:job_name="SALESMAN";break;
			case 3:job_name="CLERK";break;
			case 4:job_name="ANALYST";break;
			default:
				job_name="SALESMAN";
		}
		switch(option){
			case 1:salary=80000;break;
			case 2:salary=50000;break;
			case 3:salary=65000;break;
			case 4:salary=70000;break;
			default:
				salary=50000;
		}
		scan.close();
		
		
		// creating configuration object
		
		Configuration cfg = new Configuration();
		
		cfg.configure("hibernate.cfg.xml");
		
		try (SessionFactory factory = cfg.buildSessionFactory()) {
			Session session = factory.openSession();
			
			@SuppressWarnings("rawtypes")
			Query q = session.createQuery("SELECT emp_id FROM Employee ORDER BY emp_id DESC");
			@SuppressWarnings("unchecked")
			List<Integer> list = q.list();
			emp_id = list.get(0);
			emp_id = emp_id + 1;
			System.out.println("emp_id "+emp_id);
			Transaction t = session.beginTransaction();
			Employee emp = new Employee();
			emp.setEmp_id(emp_id);
			emp.setEmp_name(emp_name);
			emp.setJob_name(job_name);
			emp.setSalary(salary);
			session.save(emp);
			t.commit();
			session.close();
			
			System.out.println("Succesfully saved");
		} 
	}
}
