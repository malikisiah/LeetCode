# Final modification to user's code to ensure all "ninja words" are counted.

def findNinjaWordsScore(targetWords, sentence):
    total_score = 0
    # Convert everything to lowercase
    targetWords = [word.lower() for word in targetWords]
    sentence = sentence.lower()
    
    for word in targetWords:
        max_score = 0
        sent_ptr = 0  # Pointer for iterating through the sentence
        
        # Add space at the end of the sentence to ensure the last word is also checked
        sentence_with_space = sentence + ' '
        
        # Iterate through the sentence
        while sent_ptr < len(sentence_with_space):
            word_ptr = 0  # Pointer for iterating through the target word
            start_idx = sent_ptr  # To keep track of the starting index of a potential ninja word in the sentence
            
            # Inner loop to search for the target word starting from the current position in the sentence
            for inner_ptr in range(sent_ptr, len(sentence_with_space)):
                # If a character in the sentence matches with the character in the target word
                if sentence_with_space[inner_ptr] == word[word_ptr]:
                    word_ptr += 1  # Move the pointer of the target word forward
                    
                    # If the target word is completely found in the sentence
                    if word_ptr == len(word):
                        # Check if the word is separated by spaces (or at the start/end of the sentence)
                        if (start_idx == 0 or sentence_with_space[start_idx - 1] == ' ') and (sentence_with_space[inner_ptr + 1] == ' '):
                            current_score = 1  # Base score for a found ninja word
                            max_score = max(max_score, current_score)
                        
                        break  # Break the inner loop
                
            sent_ptr += 1  # Move the pointer of the sentence forward
        
        total_score += max_score

    return total_score

# Test the function
targetWords = ['Sun', 'Moon', 'Star', 'Planet']
sentence = "All the stars under the sky twinkle in slo mo on a clear night"
findNinjaWordsScore(targetWords, sentence)
