def isAPalindrome(string):
    if string == string[::-1]:
        return True
    else:
        return False


word = input()
while isAPalindrome(word):
    if(len(word) == 0):
        break
    word = word[1:]

print(len(word))

