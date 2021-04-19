package sidpro;

import java.io.Serializable;

public class StudentBean implements Serializable {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private String firstName; 	// Student first name
	private String lastName; 	// Student last name
	private String password; 		// Student password
	private String gender; 		// Student gender
	private String enNo; 			// Student Enrollment no
	/**
	 * 
	 */
	public StudentBean() {
	}
	/**
	 * @param firstName
	 * @param lastName
	 * @param password
	 * @param gender
	 * @param enNo
	 */
	public StudentBean(String firstName, String lastName, String password, String gender, String enNo) {
		this.firstName = firstName;
		this.lastName = lastName;
		this.password = password;
		this.gender = gender;
		this.enNo = enNo;
	}
	/**
	 * @return the firstName
	 */
	public String getFirstName() {
		return firstName;
	}
	/**
	 * @param firstName the firstName to set
	 */
	public void setFirstName(String firstName) {
		this.firstName = firstName;
	}
	/**
	 * @return the lastName
	 */
	public String getLastName() {
		return lastName;
	}
	/**
	 * @param lastName the lastName to set
	 */
	public void setLastName(String lastName) {
		this.lastName = lastName;
	}
	/**
	 * @return the city
	 */
	public String getPassword() {
		return password;
	}
	/**
	 * @param city the city to set
	 */
	public void setPassword(String password) {
		this.password = password;
	}
	/**
	 * @return the gender
	 */
	public String getGender() {
		return gender;
	}
	/**
	 * @param gender the gender to set
	 */
	public void setGender(String gender) {
		this.gender = gender;
	}
	/**
	 * @return the enNo
	 */
	public String getEnNo() {
		return enNo;
	}
	/**
	 * @param enNo the enNo to set
	 */
	public void setEnNo(String enNo) {
		this.enNo = enNo;
	}
	
}
