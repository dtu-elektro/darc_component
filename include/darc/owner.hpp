/*
 * Copyright (c) 2011, Prevas A/S
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Prevas A/S nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * DARC Owner class
 *
 * \author Morten Kjaergaard
 */

#ifndef __DARC_OWNER_H_INCLUDED__
#define __DARC_OWNER_H_INCLUDED__

#include <boost/asio/io_service.hpp>
#include <boost/weak_ptr.hpp>
#include <darc/primitive.h>

namespace darc
{

namespace python
{
class OwnerProxy;
}

class Node;

class Owner
{
  friend class darc::python::OwnerProxy;

protected:
  typedef std::map<ID, boost::weak_ptr<Primitive> > PrimitiveListType;
  PrimitiveListType list_;

  typedef std::map<int, int> PrimitiveTypeCountType;
  PrimitiveTypeCountType type_count_;

public:
  virtual boost::asio::io_service * getIOService() = 0;
  virtual const bool& isAttached() = 0;
  virtual boost::shared_ptr<darc::Node> getNode() = 0;
  virtual const ID& getComponentID() = 0;

  void startPrimitives();
  void stopPrimitives();
  void pausePrimitives();
  void unpausePrimitives();
  void triggerPrimitivesOnAttach();
  int add(Primitive * item);
  virtual void startProfiling();
  virtual void stopProfiling();

  void addPrimitive(Primitive * prim)
  {
    // todo: replace calls;
    add(prim);
  }

};

}

#endif
