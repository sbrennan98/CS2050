"""
Deal 2 hands of 5 cards each
"""

import random

suits = ['♠︎', '♣︎', '♥︎', '♦︎']
values = ['A', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K']

cards = []
for suit in suits:
    for value in values:
        cards.append(value + suit)

hand = []
num_players = 3
while num_players > 0:
    for n in range(5):
        card = random.choice(cards)
        cards.remove(card)
        hand.append(card)
    print('Hand', num_players, (hand))
    num_players -= 1
    hand.clear()