import tkinter as tk
from tkinter import messagebox
import os
import sys

import os
import sys

dll_path = os.path.join(os.path.dirname(__file__), "mingw_runtime")
if hasattr(os, 'add_dll_directory'):
    os.add_dll_directory(dll_path)
else:
    os.environ["PATH"] = dll_path + os.pathsep + os.environ["PATH"]

import wordle_module

class WordleApp:
    def __init__(self,root):
        self.root = root
        self.root.title("Wordle GUI")
        self.root.geometry("500x600")

        self.game = wordle_module.Wordle("wordList.txt")
        self.attempt = 0
        self.max_attempts = 6

        self.guess_var = tk.StringVar()

        self.label = tk.Label(root, text="Enter a 5-letter word:")
        self.label.pack(pady=10)

        self.entry = tk.Entry(root, textvariable=self.guess_var)
        self.entry.pack()
        self.entry.bind("<Return>", self.make_guess)

        self.feedback_frame = tk.Frame(root)
        self.feedback_frame.pack(pady=10)

    def make_guess(self, event=None):
         guess = self.guess_var.get().lower()
         if len(guess) !=5:
             messagebox.showwarning("Invalid", "Please enter a 5-letter word.")
             return

         feedback = self.game.evaluate_guess(guess)
         self.display_feedback(guess, feedback)
         self.attempt += 1

         if feedback == "GGGGG":
             messagebox.showinfo("Wordle", "Congratulations! You guessed the right word!")
             self.root.quit()
         elif self.attempt >= self.max_attempts:
             correct = self.game.get_target_word()
             messagebox.showinfo("Wordle", f"Out of attempts! The correct word was: {correct.upper()}. Restart the game.")
             self.root.quit()

    def display_feedback(self, guess, feedback) :
        row = tk.Frame(self.feedback_frame)
        row.pack()

        for i in range(5):
            color = "gray"
            if feedback[i] == 'G':
                color = "green"
            elif feedback[i] == 'Y':
                color = "yellow"

            label = tk.Label(row, text=guess[i].upper(), width=4, height=2, font=("Times New Roman", 16, "bold"), 
                             bg=color, fg="black", relief="groove", bd=2)
            label.pack(side=tk.LEFT, padx=2, pady=2)

        self.guess_var.set("")

if __name__ == '__main__':
    root = tk.Tk()
    app = WordleApp(root)
    root.mainloop()
