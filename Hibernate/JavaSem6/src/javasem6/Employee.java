/**
 * 
 */
package javasem6;

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
public class Employee {
	private int emp_id;
	private String emp_name;
	private String job_name;
	private int salary;
	/**
	 * 
	 */
	public Employee() {
	}
	/**
	 * @return the emp_id
	 */
	public int getEmp_id() {
		return emp_id;
	}
	/**
	 * @param emp_id the emp_id to set
	 */
	public void setEmp_id(int emp_id) {
		this.emp_id = emp_id;
	}
	/**
	 * @return the emp_name
	 */
	public String getEmp_name() {
		return emp_name;
	}
	/**
	 * @param emp_name the emp_name to set
	 */
	public void setEmp_name(String emp_name) {
		this.emp_name = emp_name;
	}
	/**
	 * @return the job_name
	 */
	public String getJob_name() {
		return job_name;
	}
	/**
	 * @param job_name the job_name to set
	 */
	public void setJob_name(String job_name) {
		this.job_name = job_name;
	}
	/**
	 * @return the salary
	 */
	public int getSalary() {
		return salary;
	}
	/**
	 * @param salary the salary to set
	 */
	public void setSalary(int salary) {
		this.salary = salary;
	}
	
}
