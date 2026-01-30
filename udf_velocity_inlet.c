/***********************************************************************/
/* cyl1_velocity_inlet.c                                               */
/*                                                                     */
/* Pulsatile inlet velocity condition                                  */
/*                                                                     */
/* Antoine BERTRAND                                                    */
/* Colorado State University                                           */
/* Department of Mechanical Engineering                                */
/***********************************************************************/

#include "udf.h"

// Global constants
#define RPM 3000 // Engine speed in revolutions per minute
#define V_MEAN 20.0 // Desired average exhaust velocity in m/s
#define V_MAX (M_PI * V_MEAN / 2) // Maximum velocity calculated from the desired average
#define T_OPEN 0.008 // Duration for which the valve remains open (in seconds)
#define T_CYCLE (60.0 / RPM) // Time for one engine cycle for a single cylinder (in seconds)
#define M_PI 3.14159265359

// Define the UDF for velocity at the inlet of a specific cylinder
  DEFINE_PROFILE(inlet_velocity_cyl1, thread, position)
  {
     face_t f;
     real t = CURRENT_TIME; // Get the current simulation time
     real velocity = 0.0; // Initialize the velocity to 0

    // Manually compute the modulo (remainder of division)
     t = t - 0.0; // Adjust time by the offset
     t = t - T_CYCLE * floor(t / T_CYCLE); // Manual modulo calculation

    // Calculate the sinusoidal velocity during the valve opening period
     if (t >= 0 && t <= T_OPEN)
         {
             velocity = V_MAX * sin(M_PI * (t / T_OPEN)); // Sinusoidal velocity profile
         }
     else
         {
             velocity = 0.0; // No flow outside the valve opening period
         }

    // Apply the velocity to all cells on the inlet boundary
     begin_f_loop(f, thread)
     {
         F_PROFILE(f, thread, position) = velocity;
     }
     end_f_loop(f, thread)
  }

// Define the UDF for velocity at the inlet of a specific cylinder
  DEFINE_PROFILE(inlet_velocity_cyl2, thread, position)
  {
     face_t f;
     real t = CURRENT_TIME; // Get the current simulation time
     real velocity = 0.0; // Initialize the velocity to 0

    // Manually compute the modulo (remainder of division)
     t = t - 0.005; // Adjust time by the offset
     t = t - T_CYCLE * floor(t / T_CYCLE); // Manual modulo calculation

    // Calculate the sinusoidal velocity during the valve opening period
     if (t >= 0 && t <= T_OPEN)
         {
             velocity = V_MAX * sin(M_PI * (t / T_OPEN)); // Sinusoidal velocity profile
         }
     else
         {
             velocity = 0.0; // No flow outside the valve opening period
         }

    // Apply the velocity to all cells on the inlet boundary
     begin_f_loop(f, thread)
     {
         F_PROFILE(f, thread, position) = velocity;
     }
     end_f_loop(f, thread)
  }

// Define the UDF for velocity at the inlet of a specific cylinder
  DEFINE_PROFILE(inlet_velocity_cyl3, thread, position)
  {
     face_t f;
     real t = CURRENT_TIME; // Get the current simulation time
     real velocity = 0.0; // Initialize the velocity to 0

    // Manually compute the modulo (remainder of division)
     t = t - 0.010; // Adjust time by the offset
     t = t - T_CYCLE * floor(t / T_CYCLE); // Manual modulo calculation

    // Calculate the sinusoidal velocity during the valve opening period
     if (t >= 0 && t <= T_OPEN)
         {
             velocity = V_MAX * sin(M_PI * (t / T_OPEN)); // Sinusoidal velocity profile
         }
     else
         {
             velocity = 0.0; // No flow outside the valve opening period
         }

    // Apply the velocity to all cells on the inlet boundary
     begin_f_loop(f, thread)
     {
         F_PROFILE(f, thread, position) = velocity;
     }
     end_f_loop(f, thread)
  }

// Define the UDF for velocity at the inlet of a specific cylinder
  DEFINE_PROFILE(inlet_velocity_cyl4, thread, position)
  {
     face_t f;
     real t = CURRENT_TIME; // Get the current simulation time
     real velocity = 0.0; // Initialize the velocity to 0

    // Manually compute the modulo (remainder of division)
     t = t - 0.015; // Adjust time by the offset
     t = t - T_CYCLE * floor(t / T_CYCLE); // Manual modulo calculation

    // Calculate the sinusoidal velocity during the valve opening period
     if (t >= 0 && t <= T_OPEN)
         {
             velocity = V_MAX * sin(M_PI * (t / T_OPEN)); // Sinusoidal velocity profile
         }
     else
         {
             velocity = 0.0; // No flow outside the valve opening period
         }

    // Apply the velocity to all cells on the inlet boundary
     begin_f_loop(f, thread)
     {
         F_PROFILE(f, thread, position) = velocity;
     }
     end_f_loop(f, thread)
  }