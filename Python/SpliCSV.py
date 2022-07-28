import pandas as pd


# provide file_name
file_name = 'data.csv'
# number of files you want to split csv
# -1 to evenly split csv by number_Of_lines
number_Of_files = -1
# number of rows you want in every file
# -1 to evenly split csv by number_Of_files
number_Of_lines = -1


#df = pd.read_csv('data.csv',nrows=8,skip_blank_lines=True,skiprows=0)
df = pd.read_csv(file_name,skip_blank_lines=True)

if number_Of_files == -1 and number_Of_lines > 0:
    number_Of_files = len(df.index)//number_Of_lines
    
if number_Of_files > 1 and number_Of_lines == -1:
    number_Of_lines = len(df.index)//number_Of_files

prev = -1
if number_Of_files > 1:
    number_Of_files+=1 
    for i in range(1,number_Of_files):
        line = number_Of_lines * i
        if i != number_Of_files-1:
            tempDf = df[((prev <= df.index) & (df.index < line))]
        else:
            tempDf = df[prev <= df.index]
        file_name = 'data_'+str(i)+'.csv'
        tempDf.to_csv(file_name,index=False)
        prev = line

'''
print(df['month_number'])
first_half = df[df.index < 5]
print(first_half)
first_half.to_csv('out.csv',index=False)
'''