import numpy as np
import pandas as pd
from IPython.display import display, HTML
df = pd.read_excel(r'C:/Users/gabur/Downloads/CONSOLIDATED PRESENATION MASTER DATA.xlsx', engine='openpyxl',sheet_name='JAN.21')
df.head()
# Presentation Mode
#  Final Remark
#  Clearence received Date
#  EMI COLLECTED MODE
# EMI received date
paid = df[df["Final Remark"]=='PAID']
no_mode_with_razorpay = paid[(paid["Presentation Mode"]=='CASH') | (paid["Presentation Mode"]=='NEFT') | (paid["Presentation Mode"]=='RAZORPAY')]
no_mode_without_razorpay = paid[(paid["Presentation Mode"]=='CASH') | (paid["Presentation Mode"]=='NEFT')]
no_mode_A = len(no_mode_with_razorpay.index)
no_mode_B = len(no_mode_without_razorpay.index)
# year,month,day
# pd.Timestamp(2022,1,13)
Clearence_received = no_mode_with_razorpay[no_mode_with_razorpay["Clearence received Date"]==pd.Timestamp(2022,1,13)]["Loan Account number"]
Clearence_received.to_csv("Clearence_received.csv", index=False)
mode_with_razorpay = paid[((paid["Presentation Mode"]=='ESCROW') | (paid["Presentation Mode"]=='NACH') | (paid["Presentation Mode"]=='PDC_BRANCH') | (paid["Presentation Mode"]=='PDC_CENTRAL OPS')) & (paid["EMI COLLECTED MODE"]!='-') & (paid["EMI COLLECTED MODE"].str[-7:]!='Cleared')]
mode_without_razorpay = mode_with_razorpay[(mode_with_razorpay["EMI COLLECTED MODE"].str[-18:]!='RAZORPAY COLLECTED') & (mode_with_razorpay["EMI COLLECTED MODE"]!='RAZORPAY')]
mode_A = len(mode_with_razorpay.index)
mode_B = len(mode_without_razorpay.index)
EMI_received = mode_with_razorpay[mode_with_razorpay["EMI received date"]==pd.Timestamp(2022,1,13)]["Loan Account number"]
final = pd.DataFrame({"No Mode A":no_mode_A,"No Mode B":no_mode_B,"Mode A":mode_A,"Mode B":mode_B,"No Mode Clearence received":Clearence_received,"Mode EMI received":EMI_received})
final.to_excel("foo.xlsx", sheet_name="Sheet1")


