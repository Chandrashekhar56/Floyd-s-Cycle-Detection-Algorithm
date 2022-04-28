class Node_of_Linkedlist:
	def __init__(self, data):
		self.data_part = data
		self.next_part = None
head_pointer = None
def findLoop(head_pointer):
	temp1 = head_pointer
	temp2 = head_pointer

	while (temp1 != None and temp2 != None and temp2.next_part != None):
		temp1 = temp1.next_part
		temp2 = temp2.next_part.next_part
		if (temp1 == temp2 ):
			return 1

	return 0

head_pointer = Node_of_Linkedlist(50)
head_pointer.next_part = Node_of_Linkedlist(10)
head_pointer.next_part.next_part = Node_of_Linkedlist(30)
head_pointer.next_part.next_part.next_part = Node_of_Linkedlist(20)
head_pointer.next_part.next_part.next_part.next_part = Node_of_Linkedlist(40)

temporary = head_pointer
while (temporary.next_part != None):
	temporary = temporary.next_part

temporary.next_part = head_pointer

if (findLoop(head_pointer)):
	print("Loop exists in the Linked List")
else:
	print("Loop does not exists in the Linked List")
