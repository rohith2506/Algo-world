/*
AI for paddle bot

Algorithm:-
--> Caluculating co-ordinates for every rock based on distance and angle given.
--> The rock position was given by (distance, radians).
--> The paddle position is given by (paddle_y).
      
                                /|(paddle position)
                               / |
                   (distance) /  | 
                             /   | (vertical_distance)
                            /    |
            (rock position)/_____|
                             (horizontal_distance) 
                             
                 Fig. Geometrical representation of rock and paddle positions
         
    Now, by using fundementals of trigonometry, we can calculate
        1) horizontal_distance (x_point) = cos(angle) * distance;
        2) vertical_distance (y_point) = sin(angle) * distance;
    
so, finally we need to find rock which is closer to paddle (based on x_point) and caluculate it's y_point and move the paddle.
       
Paddle movement direction is determined by angle.
       --> if angle is negative, it's an obtuse angle and hence rock is at higher position than paddle, hence paddle moves upward.
       --> if angle is positive, it's an acute angle and hence rock is at lower position than paddle, hence paddle moves downward

@Author: Rohith
*/

defender.start(
  function notify_player(rocks, paddle_y){
      var moves = [];
      var shortest_distance =  100.0, index, x_point;

      // calculating nearest rock based on x-point
      for(var i=0; i < rocks.length; i++) {
          x_point = Math.cos(rocks[i].radians) * rocks[i].distance;
          if(x_point < shortest_distance) {
              shortest_distance = x_point;
              index = i;
          }
      }

      // calculating y-point which determines number of steps paddle shall move
      var closest_distance = rocks[index].distance;
      var closest_angle = rocks[index].radians;
      var y_point = Math.sin(closest_angle) * closest_distance;
      y_point = Math.abs(Math.round(y_point));
      
      
      //Determining direction of movement based on angle.
      if(closest_angle < 0.0) {
          for(var step = 0; step < y_point; step++) {
              moves.push(1);
          }
          for(step = y_point; step < Math.round(x_point); step++) {
              moves.push(0);
          }
      }
      else if(closest_angle > 0.0) {
          for(var step = 0; step < y_point; step++) {
              moves.push(-1);
          }
          for(step = y_point; step < Math.round(x_point); step++) {
              moves.push(0);
          }
      }
      else {}
      
      return moves;
  }
);

