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

#include <occupancy_map_server/occupancy_map_server.h>
#include <occupancy_map_server/point_cloud_occupancy_map_updater.h>

namespace occupancy_map_server
{
	OccupancyMapServer::OccupancyMapServer(const boost::shared_ptr<tf::Transformer> tf) : tree_(0.1)
	{
		/* This will eventually load different updaters depending on config params */
		boost::shared_ptr<OccupancyMapUpdater> up = boost::make_shared<PointCloudOccupancyMapUpdater>("base_link", "/camera/rgb/points", tf);
		up->setOctree(&tree_, &tree_mutex_);
		map_updaters_.push_back(up);
	}

	void OccupancyMapServer::run()
	{
		/* Initialize all of the occupancy map updaters */
		std::vector<boost::shared_ptr<OccupancyMapUpdater> >::iterator it;
		for(it = map_updaters_.begin(); it != map_updaters_.end(); it++)
		{
			(*it)->initialize();
			(*it)->start();
		}

		ros::spin();
	}

	OccupancyMapServer::~OccupancyMapServer(void)
	{}
}
