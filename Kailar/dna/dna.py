import csv
import sys

#Lists
database = []
samplefile = []

#Main Function
def main():
    #Checks command line arguments
    if len(sys.argv) != 3:
        print("Input csv file and sequence only")
        sys.exit(1)
    
    #Reads database into memory
    databasefile = sys.argv[1]
    with open(databasefile, "r") as file:
        reader = csv.reader(file)
        
        for row in reader:
            database.append(row)
            
    #Reads sample sequence into memory
    samplefile = sys.argv[2]
    with open(samplefile, "r") as file:
        sample = file.readline()

    #Loops through database and runs fineSTR function on each person and their STRs
    counter = 0
    for i in range(1, len(database)):
        for j in range(1, len(database[i])):
            test = database[0][j]
            rep = fineSTR(test, sample)
            dbSTR = int(database[i][j])
            if rep == dbSTR:
                counter += 1
                if counter == len(database[0]) - 1:
                    #Prints the match's name
                    print(database[i][0])
                    sys.exit(0)
            else:
                counter = 0
                break
    print("No Match")

#Custom function that loops through the sample sequence and finds how many repeats of each STR there are
def fineSTR(STR, sample):
    #Loop through sample with length of STR
    counter = 0
    maxSTR = 0
    lenSTR = len(STR)
    lenSamp = len(sample)
    for i in range(0, lenSamp):
        #If we fine the STR
        s = sample[i:i+lenSTR]
        if s == STR:
            for j in range(i, lenSamp, lenSTR):
                samp = sample[j:j + lenSTR]
                if samp == STR:
                    counter += 1
                else:
                    if counter > maxSTR:
                        maxSTR = counter
                    counter = 0
                    break
    return maxSTR

#Call back to Main
main()