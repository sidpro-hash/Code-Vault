/**
 * 
 */
package javasem6;

import java.util.Iterator;
import java.util.List;

import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.cfg.Configuration;

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
public class DisplayData {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		// creating configuration object
		
				Configuration cfg = new Configuration();
				
				cfg.configure("hibernate.cfg.xml");
				
				try (SessionFactory factory = cfg.buildSessionFactory()) {
					Session session = factory.openSession();
					
				
					@SuppressWarnings("rawtypes")
					List employees = session.createQuery("FROM Employee ORDER BY emp_id ASC").list(); 
					
			         for (@SuppressWarnings("rawtypes")
					Iterator iterator = employees.iterator(); iterator.hasNext();){
			            Employee employee = (Employee) iterator.next();
			            System.out.print("Employee Id: " + employee.getEmp_id());
			            System.out.print("   First Name: " + employee.getEmp_name()); 
			            System.out.print("   Job Name: " + employee.getJob_name()); 
			            System.out.println("   Salary: " + employee.getSalary()); 
			         }
					
					session.close();
					
					
				} 
	}

}
