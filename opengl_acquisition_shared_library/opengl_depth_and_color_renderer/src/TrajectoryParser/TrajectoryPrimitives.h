/** @file TrajectoryPrimitives.h
* @brief A tool that scans for a string in a very fast and robust way
* @author Ammar Qammaz (AmmarkoV)
*/

#ifndef TRAJECTORYPRIMITIVES_H_INCLUDED
#define TRAJECTORYPRIMITIVES_H_INCLUDED


/** @brief Enumerator for the IDs of TrajectoryPrimitives so we can know what the result was*/
enum { 
 TRAJECTORYPRIMITIVES_EMPTY=0,
 TRAJECTORYPRIMITIVES_COMMENT, // 1 
 TRAJECTORYPRIMITIVES_ARROW, // 2 
 TRAJECTORYPRIMITIVES_POS, // 3 
 TRAJECTORYPRIMITIVES_DEBUG, // 4 
 TRAJECTORYPRIMITIVES_TIMESTAMP, // 5 
 TRAJECTORYPRIMITIVES_AUTOREFRESH, // 6 
 TRAJECTORYPRIMITIVES_INTERPOLATE_TIME, // 7 
 TRAJECTORYPRIMITIVES_BACKGROUND, // 8 
 TRAJECTORYPRIMITIVES_COMPOSITE_OBJECT, // 9 
 TRAJECTORYPRIMITIVES_RIGID_OBJECT, // 10 
 TRAJECTORYPRIMITIVES_OBJECTTYPE, // 11 
 TRAJECTORYPRIMITIVES_OBJECT, // 12 
 TRAJECTORYPRIMITIVES_OBJ, // 13 
 TRAJECTORYPRIMITIVES_EVENT, // 14 
 TRAJECTORYPRIMITIVES_PROJECTION_MATRIX, // 15 
 TRAJECTORYPRIMITIVES_EMULATE_PROJECTION_MATRIX, // 16 
 TRAJECTORYPRIMITIVES_MODELVIEW_MATRIX, // 17 
 TRAJECTORYPRIMITIVES_SCALE_WORLD, // 18 
 TRAJECTORYPRIMITIVES_OFFSET_ROTATIONS, // 19 
 TRAJECTORYPRIMITIVES_MAP_ROTATIONS, // 20 
 TRAJECTORYPRIMITIVES_FRAME_RESET, // 21 
 TRAJECTORYPRIMITIVES_FRAME, // 22 
 TRAJECTORYPRIMITIVES_AFFIX_OBJ_TO_OBJ_FOR_NEXT_FRAMES, // 23 
 TRAJECTORYPRIMITIVES_INCLUDE, // 24 
 TRAJECTORYPRIMITIVES_MOVE_VIEW, // 25 
 TRAJECTORYPRIMITIVES_SMOOTH, // 26 
 TRAJECTORYPRIMITIVES_OBJ_OFFSET, // 27 
 TRAJECTORYPRIMITIVES_CONNECTOR, // 28 
 TRAJECTORYPRIMITIVES_HAND_POINTS, // 29 
 TRAJECTORYPRIMITIVES_END_OF_ITEMS
};



/** @brief Scan a string for one of the words of the TrajectoryPrimitives word set
* @ingroup stringParsing
* @param Input String , to be scanned
* @param Length of Input String
* @retval See above enumerator*/
 int scanFor_TrajectoryPrimitives(const char * str,unsigned int strLength); 

#endif
