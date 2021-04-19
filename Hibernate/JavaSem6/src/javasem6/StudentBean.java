package javasem6;

import java.io.Serializable;

public class StudentBean implements Serializable {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private String firstName; 	// Student first name
	private String lastName; 	// Student last name
	private String city; 		// Student city name
	private String gender; 		// Student gender
	private Long enNo; 			// Student Enrollment no
	/**
	 * 
	 */
	public StudentBean() {
	}
	/**
	 * @param firstName
	 * @param lastName
	 * @param city
	 * @param gender
	 * @param enNo
	 */
	public StudentBean(String firstName, String lastName, String city, String gender, Long enNo) {
		this.firstName = firstName;
		this.lastName = lastName;
		this.city = city;
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
	public String getCity() {
		return city;
	}
	/**
	 * @param city the city to set
	 */
	public void setCity(String city) {
		this.city = city;
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
	public Long getEnNo() {
		return enNo;
	}
	/**
	 * @param enNo the enNo to set
	 */
	public void setEnNo(Long enNo) {
		this.enNo = enNo;
	}
	
}
