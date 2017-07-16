import numpy as np

def num2letter(num):
	#65-90
	asc_num = num + 65
	return chr(asc_num)
	
def main():
	encrypted_words = [10,22,2,19]
	n = len(encrypted_words)

	decrypet_words = [0]*n
	#??what if a word only has one letter
	if n==1:
		print("Not Know What To Do")
	decrypet_words[1] = encrypted_words[0]
	decrypet_words[n-2] = encrypted_words[n-1]
	
if __name__ == '__main__':
    main()
