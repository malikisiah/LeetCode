# Extend the trainSchedule function to handle passenger boarding and departure

def trainSchedule(arrivalStations, arrivalTimes, destStations, destTimes, timeBtwStations):
    # Number of passengers who reach their destinations on time
    on_time_passengers = 0
    
    # Sort passengers by arrival time and index (to handle passengers arriving at the same time)
    passengers = sorted(zip(arrivalStations, arrivalTimes, destStations, destTimes), key=lambda x: (x[1], x[0]))
    
    # Queue to hold trains; each train is represented as a tuple (current station, time of departure, passenger count)
    trains = deque()
    
    # Queue to hold waiting passengers at each station; key is station number
    waiting_passengers = {}
    
    # Current time starts at 6:30 am (0630 in 24-hour format)
    current_time = 630
    
    # Initialize the first train at station 1 at 6:30 am
    trains.append((1, addMinutes(current_time, 2), 0))  # (current station, time of departure, passenger count)
    
    # Index to keep track of the next passenger to check
    next_passenger = 0
    
    # Simulate the train system minute-by-minute
    while next_passenger < len(passengers):
        # Update trains
        new_trains = deque()
        for station, departure_time, count in trains:
            if current_time == departure_time:
                # Move the train to the next station
                next_station = station + 1
                next_departure_time = addMinutes(current_time, timeBtwStations + 2)
                new_trains.append((next_station, next_departure_time, count))
            else:
                # Train is still at the current station
                
                # Handle passenger boarding and departure
                if station in waiting_passengers:
                    # Board passengers if there is space
                    while waiting_passengers[station] and count < 5:
                        _, dest_time, dest_station = waiting_passengers[station].popleft()
                        arrival_at_dest = addMinutes(current_time, (dest_station - station) * (timeBtwStations + 2))
                        
                        # Check if the passenger will reach on time
                        if arrival_at_dest <= dest_time:
                            on_time_passengers += 1
                        
                        count += 1
                
                new_trains.append((station, departure_time, count))
                
        trains = new_trains
        
        # Check for passengers arriving at stations
        while next_passenger < len(passengers):
            arrival_station, arrival_time, dest_station, dest_time = passengers[next_passenger]
            if arrival_time > current_time:
                break  # No more passengers arriving at this minute
            
            # Add the passenger to the waiting queue at their arrival station
            if arrival_station not in waiting_passengers:
                waiting_passengers[arrival_station] = deque()
            waiting_passengers[arrival_station].append((arrival_time, dest_time, dest_station))
            
            next_passenger += 1
        
        # Update current time
        current_time = addMinutes(current_time, 1)
        
        # Add a new train every 15 minutes starting at 6:30 am
        if current_time % 100 % 15 == 0:
            trains.append((1, addMinutes(current_time, 2), 0))
    
    return on_time_passengers

# Sample input (for testing purposes)
arrivalStations = [1, 2, 1]
arrivalTimes = [630, 635, 640]
destStations = [3, 4, 2]
destTimes = [700, 730, 700]
timeBtwStations = 5

# Call the function
trainSchedule(arrivalStations, arrivalTimes, destStations, destTimes, timeBtwStations)
