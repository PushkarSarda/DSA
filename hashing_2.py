size=10
hash_table=[None]*size

def add_word():
    key=input("Enter the word to be enterd")
    ascii_sum=0
    for i in range(len(key)):
        ascii_sum+=ord(key[i])
    index=ascii_sum%size
    meaning=input("Enter the meaning of the word: ")
    entry=[key,meaning]
    for i in range(size):
        if hash_table[index]==None:
            hash_table[index]=entry
            print("Client Added Successfully at ",index,"   ",entry)
            break
        else:
            index=(index+1)%size

def search_word():
    key_search=input("Enter the word to be searched: ")
    ascii_sum=0
    for i in range(len(key_search)):
        ascii_sum+=ord(key_search[i])
    index=ascii_sum%size
    flag=0
    for i in range(size):
        if(hash_table[index][0]==key_search):
            print("Word: ",hash_table[index][0],"\tMeaning: ",hash_table[index][1])
            flag=1
            break
        else:
            index=(index+1)%size
    if flag==0:
        print("Word not found!")

def del_word():
    key_del=input("Enter the word to be deleted: ")
    ascii_sum=0
    for i in range(len(key_del)):
        ascii_sum+=ord(key_del[i])
    index=ascii_sum%size
    flag=0
    for i in range (size):
        if(hash_table[index][0]==key_del):
            print("Word: ",hash_table[index][0],"\tMeaning: ",hash_table[index][1],"\tHas been DELETED!!")
            flag=1
            break
        else:
            index=(index+1)%size
    if(flag==0):
        print("Word doesnt exist!")

def main():
    for i in range (size):
        add_word()
    while(True):
        search_word()
    
main()


