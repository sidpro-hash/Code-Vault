/**
 * 
 */
package com.sidpro;

import javax.faces.bean.ManagedBean;

/**
 * @author MG
 *
 */
@ManagedBean
public class Marks {
	private int DM,ADJ,DV,TOC,MPI;
	private String MarDM="DM",MarADJ="ADJ",MarDV="DV",MarTOC="TOC",MarMPI="MPI";
	/**
	 * 
	 */
	public Marks() {
	}

	/**
	 * @return the dM
	 */
	public int getDM() {
		return DM;
	}

	/**
	 * @param dM the dM to set
	 */
	public void setDM(int dM) {
		DM = dM;
	}

	/**
	 * @return the aDJ
	 */
	public int getADJ() {
		return ADJ;
	}

	/**
	 * @param aDJ the aDJ to set
	 */
	public void setADJ(int aDJ) {
		ADJ = aDJ;
	}

	/**
	 * @return the dV
	 */
	public int getDV() {
		return DV;
	}

	/**
	 * @param dV the dV to set
	 */
	public void setDV(int dV) {
		DV = dV;
	}

	/**
	 * @return the tOC
	 */
	public int getTOC() {
		return TOC;
	}

	/**
	 * @param tOC the tOC to set
	 */
	public void setTOC(int tOC) {
		TOC = tOC;
	}

	/**
	 * @return the mPI
	 */
	public int getMPI() {
		return MPI;
	}

	/**
	 * @param mPI the mPI to set
	 */
	public void setMPI(int mPI) {
		MPI = mPI;
	}
	
	

	public String Grade(int s){
		if(s>=85)return "AA";
		else if(s>=75)return "AB";
		else if(s>=65)return "BB";
		else if(s>=55)return "BC";
		else if(s>=45)return "CC";
		else if(s>=40)return "CD";
		else if(s>=35)return "DD";
		return "FF";
	}

	/**
	 * @return the marDM
	 */
	
	/**
	 * @param marDM the marDM to set
	 */
	public void setMarDM(String marDM) {
		this.MarDM = marDM;
	}

	/**
	 * @param marADJ the marADJ to set
	 */
	public void setMarADJ(String marADJ) {
		MarADJ = marADJ;
	}

	/**
	 * @param marDV the marDV to set
	 */
	public void setMarDV(String marDV) {
		MarDV = marDV;
	}

	/**
	 * @param marTOC the marTOC to set
	 */
	public void setMarTOC(String marTOC) {
		MarTOC = marTOC;
	}

	/**
	 * @param marMPI the marMPI to set
	 */
	public void setMarMPI(String marMPI) {
		MarMPI = marMPI;
	}
	public String getMarADJ() {
		MarADJ = this.Grade(ADJ);
		return MarADJ;
	}
	
	
	
	
	/**
	 * @return the marDM
	 */
	

	/**
	 * @return the marADJ
	 */
	public String getMarDM() {
		MarDM = this.Grade(DM);
		return MarDM;
	}

	/**
	 * @return the marDV
	 */
	public String getMarDV() {
		MarDV = this.Grade(DV);
		return MarDV;
	}

	/**
	 * @return the marTOC
	 */
	public String getMarTOC() {
		MarTOC = this.Grade(TOC);
		return MarTOC;
	}

	/**
	 * @return the marMPI
	 */
	public String getMarMPI() {
		MarMPI = this.Grade(MPI);
		return MarMPI;
	}
}
