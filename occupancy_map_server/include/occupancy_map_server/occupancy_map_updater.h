/*********************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2011, Willow Garage, Inc.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the Willow Garage nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************/

/* Author: Jon Binney */

#ifndef MOVEIT_OCCUPANCY_MAP_UPDATER_H_
#define MOVEIT_OCCUPANCY_MAP_UPDATER_H_

#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>
#include <octomap/octomap.h>

namespace occupancy_map_server
{
	/**
	 * @class OccupancyMapUpdater
	 * Base class for classes which update the occupancy map.
	 */
	class OccupancyMapUpdater
	{
	public:
		/** @brief Constructor
		 *  @param cond Condition variable used to notify the server when we are ready to update the map
		 */
      OccupancyMapUpdater() {}
      
      /** @brief Do any necessary setup (subscribe to ros topics, etc.)*/
      virtual void initialize(void) = 0;
      
      /** @brief Update the octree*/
      virtual void process(octomap::OcTree *tree) = 0;
        
	};
}

#endif /* MOVEIT_OCCUPANCY_MAP_UPDATER_H_ */
