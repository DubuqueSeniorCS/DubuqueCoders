Information="""
/***
Automates the basic Writing of a Java Class
Author: Liam Johnston
Date: 10/13/2016
Info: When you are done with instance fields enter a blank new instance ex:
to print out the basic java class
Version 3.0 
+Setters for variables
+Infinite Variables
-Alpabet
***/
"""
import time#Import the time module to slow down code so that it is possible to copy result
#Defining Variables
cn=input("\n\n\nClass Name: ")#Asks the user for the name of the class
print("\n")#/n prints a space so that the user may visually see the change in request

#it is used to store the type of the instance fields
global it#makes a variable global so that all methods can use it
#Similar to private String it; minus the String part that is definited next
global int_name#int_name keeps the names of the instance fields
global counter

it=""#Defining the type that the it 
int_name=""#Defining the fact that int_name is an empty String
counter=0 # used for limiting the number of loops to the amount of instance fields


#Template is used to print the readable copied code
def Template(T1, T2, T3, U1):#Upon calling the Template method you need to define the
#Name of the class, the types of the variables, the names of the variables, and a 
#number of the amount of instance fields
    #T1 ClassName, T2 Type, T3 Name, U1 number of instance fields
    print(Information)
    print("\n\n","-"*30,"\n\n")#Gives some elbow room
    print("public class ",T1,"{")
    print("//Instance Fields")
    
    #Seperate the different types and names
    one_sep=T2.split()#All .Split does is makes sure that all the items in the String 
    #name are seperate and different to help with later coding
    two_sep=T3.split()
    
    #backup_U1 = 0
    backup_U1 = U1#This is used for restoring the amount of 
    #Instance fields so that the forevers only run for so long.
    pop = U1# I got lazy so I made a second one / I forgot about backup_U1
    #Prints the items in the list
    for item in T2.split():#For each number of types run this code
        U1 -= 1#Lowers the counter
        print("private",one_sep[U1], two_sep[U1],";")#prints intial calling of class but not
        #just that but using the [] to save me lots of code
        
    U1 = backup_U1 #resets U1
    #Class Constructor
    print("//Class Constructor")
    print("public",T1,"(")
    
    ##Parameters of Constructor
    for item in T2.split():
        U1 -= 1
        print(one_sep[U1], two_sep[U1])
        if U1 > 0:
            print(", ")
    U1 = backup_U1 #resets U1
    print(")")#End Parameters
    
    print("{")
    #Sets constructed variables to the instance fields
    for item in T3.split():
        U1 -=1
        beeboop="this."+two_sep[U1]
        print(beeboop.replace(" ",""),"=" ,two_sep[U1],";")
    U1 = backup_U1 #resets U1
    print("}")
    extra_U2=U1
    #getters
    for item in T3.split():
        U1 -=1
        get= "get"+two_sep[U1].title()
        print("public",one_sep[U1], get.replace(" ",""),"(){return", two_sep[U1],";}")
        
    print("//Setters/n")
    #Setters
    #T1 ClassName, T2 Type, T3 Name, U1 number of instance fields
    for item in T2.split():
        pop -= 1
        set= " set"+two_sep[pop].title()
        helping="public void" +" "
        soup = "("+ one_sep[pop] + " " + two_sep[pop] + ")" +"{"
        kitchen = "this."+two_sep[pop]
        print(helping + set.replace(" ","")+ soup)
        
        print(kitchen.replace(" ","")+"="+two_sep[pop]+";}")#changes appropriate varibale to the given value
        if U1 > 0:
            print(", ")
    
    print("}")#End of Line
    #T1 ClassName, T2 Type, T3 Name, U1 number of instance fields
    
#This code gets the information to use for Template()
boolean=False
while boolean==False:
    cmd=input("Instance Field Type: ")
    if cmd=="":
        boolean=True
        break
    CMD=input("Instance Field Name: ")
    it += cmd + " "
    int_name += CMD + " "
    counter = 1 + counter
    print("\n")
#it = Type
#int_name = instance name
#counter = amount of instance fields
Template(cn, it, int_name, counter)
time.sleep(60)
