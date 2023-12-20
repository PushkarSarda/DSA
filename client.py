size=3
client_list=[None]*size

def add_client():
    client_id=int(input("Enter the client id:"))
    name=input("Enter the name of the client:")
    telephone_number=int(input("Enter the number:"))
    client_details=[client_id,name,telephone_number]
    index=client_id%size
    for i in range(size):
        if client_list[index]==None:
            client_list[index]=client_details
            print("Client Added Successfully at ",index,"   ",client_details)
            break
        else:
            index=(index+1)%size

def search_client():
    client_id=int(input("Enter the client-id:"))
    index=client_id%size
    for i in range(size):
        if client_list[index]!=None:
            if client_list[index][0]==client_id:
                print("Client found at index: ",index,"Client Details: ", client_list[index])
                return
            else:
                index=(index+1)%size
        else:
            print("Client not found")
    # print("Client not found!")

def delete_client():
    client_id=int(input("Enter the client id:"))
    index=client_id%size
    for i in range (size):
        if(client_list[index]!=None):
            if(client_list[index][0]==client_id):
                client_list[index]=None
                print("Client deleted!")
                break
            else:
                index=(index+1)%size
        else:
            print("Client not found!")

def main():
    for i in range (size):
        add_client()
    while(True):
        search_client()
        dec=input("enter yes to continue and no to exit search: ")
        if(dec=="no"):
            break
    while(True):
        delete_client()
        dec=input("enter yes to continue and no to exit delete: ")
        if(dec=="no"):
            break
    
main()


