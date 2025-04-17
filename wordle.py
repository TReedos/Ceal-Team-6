import random

# Load the word list
def load_word_list(filename):
    with open(filename, 'r') as file:
        words = [line.strip().lower() for line in file if len(line.strip()) == 5]
    return words

# Pick a random word
def choose_target_word(words):
    return random.choice(words)

# Main game loop
def play_game():
    words = load_word_list("wordlist.txt")
    target = choose_target_word(words)
    max_attempts = 6

    # Display the game introduction and rules
    print("Welcome to Wordle!")
    print("\nRules:")
    print("- Guess the 5-letter word. You have 6 attempts.")
    print("- After each guess, you'll get feedback based on your guess:")
    print("  - R (Red): The letter is NOT in the target word.")
    print("  - Y (Yellow): The letter is in the target word but NOT in the correct position.")
    print("  - G (Green): The letter is in the correct position.")
    print("\nLet's begin!")

    attempts = 0
    while attempts < max_attempts:
        guess = input("\nEnter your guess: ").strip().lower()

        if not guess.isalpha() or len(guess) != 5:
            print(" Guess must be exactly 5 letters.")
            continue

        print(guess)
        feedback = get_feedback(guess, target)
        print(feedback)

        if guess == target:
            print(" Correct! You guessed the word!")
            break

        attempts += 1

    if guess != target:
        print(f"\n Out of attempts! The word was: {target.upper()}")

# Generate R/Y/G feedback based on guess and target
def get_feedback(guess, target):
    feedback = ["R"] * 5
    target_chars = list(target)

    # First pass: correct positions
    for i in range(5):
        if guess[i] == target[i]:
            feedback[i] = "G"
            target_chars[i] = None  # Mark this letter used

    # Second pass: correct letters wrong positions
    for i in range(5):
        if feedback[i] == "R" and guess[i] in target_chars:
            feedback[i] = "Y"
            target_chars[target_chars.index(guess[i])] = None  # Mark used

    return ''.join(feedback)

# Run the game
if __name__ == "__main__":
    while True:
        play_game()
        again = input("\nWould you like to play again? (Y/N): ").strip().lower()
        if again != 'y':
            print("Thanks for playing! Goodbye")
            break
