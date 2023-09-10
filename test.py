def addMinutes(currentTime, minutesPassed):
    mins = currentTime % 100
    hour = currentTime // 100

    totalMinutes = mins + 60 * hour
    totalMinutes += minutesPassed

    newMinutes = totalMinutes % 60
    newHour = totalMinutes // 60

    return newHour*100 + newMinutes


#
# Complete the 'trainSchedule' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER_ARRAY arrivalStations
#  2. INTEGER_ARRAY arrivalTimes
#  3. INTEGER_ARRAY destStations
#  4. INTEGER_ARRAY destTimes
#  5. INTEGER timeBtwStations
#

def trainSchedule(arrivalStations, arrivalTimes, destStations, destTimes, timeBtwStations):
    # Write your code here