# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 1000


def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py CSVFileName")

    teams = []
    #Read teams into memory from file
    filename = sys.argv[1]
    with open(filename) as f:
        reader = csv.DictReader(f)
        for team in (reader):
            
            #Change the rating from a string to an integer
            team["rating"] = int(team["rating"])
        
            #Add the rating to the dict
            teams.append(team)
    counts = {}
    #Simulate N tournaments and keep track of win counts
    for i in range(N):
        winner = simulate_tournament(teams)
        
        #If the winner has already won a tournament, add 1 to their count
        if winner in counts:
            counts[winner] += 1
        
        #If the winner hasn't won yet, set their count status to 1
        else:
            counts[winner] = 1
    
    
    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")



#Custom functions
def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    #Loops until there is only one team left
    while len(teams) > 1:
        
        #Simulates rounds in order to eliminate teams
        teams = simulate_round(teams)
        
    #Returns the first value of the "Teams" list, which will be the winner and it only returns the name of the team, not the rating
    return teams[0]["team"]
    
      
            
if __name__ == "__main__":
    main()
