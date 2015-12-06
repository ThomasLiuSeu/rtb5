/*
 *
 * Copyright 2015, Google Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <iostream>
#include <memory>
#include <string>
#include <glog/logging.h> 
#include <gflags/gflags.h> 

#include "proto/click.grpc.pb.h"
#include "src/database.h"

using namespace RTB5;

int main(int argc, char** argv) {

  ::google::InitGoogleLogging(argv[0]); 
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  Database database;
  database.Open();
  Union haitao55;
  haitao55.set_union_id(1);
  haitao55.set_union_name("55haitao");
  haitao55.set_url_pattern("http://union.55haitao.com/index.php?mod=go"
      "&op=multiple&token=ZhZIC5HluW3vVdlO&url={origin_url}&tag={tags}");
  Union viglink;
  viglink.set_union_id(2);
  viglink.set_union_name("viglink");
  viglink.set_url_pattern("http://redirect.viglink.com?key=c569e3edee1a0b4dd14ea79c31dd172b&u={origin_url}&cuid={tags}");
  database.Insert(haitao55);
  database.Insert(viglink);

  User user;
  user.set_user_id(311);
  user.set_user_name("chanet");
  user.set_password("abcdefg2008");
  user.set_token("3123ads");
  user.set_account("account");
  database.Insert(user);
  {
    Campaign campaign;
    campaign.set_campaign_id(1);
    campaign.set_union_id(1);
    campaign.set_campaign_name("6pm");
    campaign.set_pattern("6pm");
    campaign.set_percent(0.06);
    database.Insert(campaign);
  }
  {
    Campaign campaign;
    campaign.set_campaign_id(2);
    campaign.set_union_id(1);
    campaign.set_campaign_name("skinstore");
    campaign.set_pattern("skinstore");
    campaign.set_percent(0.06);
    database.Insert(campaign);
  }
  {
    Campaign campaign;
    campaign.set_campaign_id(3);
    campaign.set_union_id(1);
    campaign.set_campaign_name("uggaustralia");
    campaign.set_pattern("uggaustralia");
    campaign.set_percent(0.06);
    database.Insert(campaign);
  }
  {
    Campaign campaign;
    campaign.set_campaign_id(4);
    campaign.set_union_id(1);
    campaign.set_campaign_name("vitacost");
    campaign.set_pattern("vitacost");
    campaign.set_percent(0.06);
    database.Insert(campaign);
  }
  {
    Campaign campaign;
    campaign.set_campaign_id(5);
    campaign.set_union_id(1);
    campaign.set_campaign_name("carters");
    campaign.set_pattern("carters");
    campaign.set_percent(0.06);
    database.Insert(campaign);
  }
  {
    Campaign campaign;
    campaign.set_campaign_id(6);
    campaign.set_union_id(1);
    campaign.set_campaign_name("joesnewbalanceoutlet");
    campaign.set_pattern("joesnewbalanceoutlet");
    campaign.set_percent(0.06);
    database.Insert(campaign);
  }
  {
    Campaign campaign;
    campaign.set_campaign_id(7);
    campaign.set_union_id(1);
    campaign.set_campaign_name("bloomingdales");
    campaign.set_pattern("bloomingdales");
    campaign.set_percent(0.06);
    database.Insert(campaign);
  }
  {
    Campaign campaign;
    campaign.set_campaign_id(8);
    campaign.set_union_id(1);
    campaign.set_campaign_name("origins");
    campaign.set_pattern("origins");
    campaign.set_percent(0.06);
    database.Insert(campaign);
  }
  {
    Campaign campaign;
    campaign.set_campaign_id(9);
    campaign.set_union_id(1);
    campaign.set_campaign_name("clinique");
    campaign.set_pattern("clinique");
    campaign.set_percent(0.06);
    database.Insert(campaign);
  }
  {
    Campaign campaign;
    campaign.set_campaign_id(10);
    campaign.set_union_id(1);
    campaign.set_campaign_name("esteelauder");
    campaign.set_pattern("esteelauder");
    campaign.set_percent(0.06);
    database.Insert(campaign);
  }
  {
    Campaign campaign;
    campaign.set_campaign_id(11);
    campaign.set_union_id(1);
    campaign.set_campaign_name("clinique");
    campaign.set_pattern("clinique");
    campaign.set_percent(0.06);
    database.Insert(campaign);
  }
  {
    Campaign campaign;
    campaign.set_campaign_id(12);
    campaign.set_union_id(1);
    campaign.set_campaign_name("esteelauder");
    campaign.set_pattern("esteelauder");
    campaign.set_percent(0.06);
    database.Insert(campaign);
  }
  {
    Campaign campaign;
    campaign.set_campaign_id(13);
    campaign.set_union_id(1);
    campaign.set_campaign_name("saksfifthavenue");
    campaign.set_pattern("saksfifthavenue");
    campaign.set_percent(0.06);
    database.Insert(campaign);
  }
  {
    Campaign campaign;
    campaign.set_campaign_id(14);
    campaign.set_union_id(1);
    campaign.set_campaign_name("ssense");
    campaign.set_pattern("ssense");
    campaign.set_percent(0.06);
    database.Insert(campaign);
  }
  {
    Campaign campaign;
    campaign.set_campaign_id(15);
    campaign.set_union_id(1);
    campaign.set_campaign_name("toryburch");
    campaign.set_pattern("toryburch");
    campaign.set_percent(0.06);
    database.Insert(campaign);
  }
  {
    Campaign campaign;
    campaign.set_campaign_id(16);
    campaign.set_union_id(1);
    campaign.set_campaign_name("victoriassecret");
    campaign.set_pattern("victoriassecret");
    campaign.set_percent(0.06);
    database.Insert(campaign);
  }
  {
    Campaign campaign;
    campaign.set_campaign_id(17);
    campaign.set_union_id(1);
    campaign.set_campaign_name("ralphlauren");
    campaign.set_pattern("ralphlauren");
    campaign.set_percent(0.06);
    database.Insert(campaign);
  }
  {
    Campaign campaign;
    campaign.set_campaign_id(18);
    campaign.set_union_id(1);
    campaign.set_campaign_name("chemistwarehouse");
    campaign.set_pattern("chemistwarehouse");
    campaign.set_percent(0.06);
    database.Insert(campaign);
  }
  {
    Campaign campaign;
    campaign.set_campaign_id(19);
    campaign.set_union_id(2);
    campaign.set_campaign_name("booking");
    campaign.set_pattern("booking");
    campaign.set_percent(0.06);
    database.Insert(campaign);
  }
  {
    Campaign campaign;
    campaign.set_campaign_id(20);
    campaign.set_union_id(1);
    campaign.set_campaign_name("saksoff5th");
    campaign.set_pattern("saksoff5th");
    campaign.set_percent(0.06);
    database.Insert(campaign);
  }
  {
    Campaign campaign;
    campaign.set_campaign_id(21);
    campaign.set_union_id(1);
    campaign.set_campaign_name("shop-apotheke");
    campaign.set_pattern("shop-apotheke");
    campaign.set_percent(0.06);
    database.Insert(campaign);
  }
  {
    Campaign campaign;
    campaign.set_campaign_id(21);
    campaign.set_union_id(1);
    campaign.set_campaign_name("shop-apotheke");
    campaign.set_pattern("shop-apotheke");
    campaign.set_percent(0.06);
    database.Insert(campaign);
  }

  {
    Campaign campaign;
    campaign.set_campaign_id(21);
    campaign.set_union_id(1);
    campaign.set_campaign_name("ASOS USA");
    campaign.set_pattern(".asos.");
    campaign.set_percent(0.06);
    database.Insert(campaign);
  }
  {
    Campaign campaign;
    campaign.set_campaign_id(22);
    campaign.set_union_id(1);
    campaign.set_campaign_name("Topshop UK");
    campaign.set_pattern("topshop");
    campaign.set_percent(0.06);
    database.Insert(campaign);
  }
  {
    Campaign campaign;
    campaign.set_campaign_id(28);
    campaign.set_union_id(1);
    campaign.set_campaign_name("Macys");
    campaign.set_pattern(".macys.");
    campaign.set_percent(0.06);
    database.Insert(campaign);
  }
  {
    Campaign campaign;
    campaign.set_campaign_id(23);
    campaign.set_union_id(1);
    campaign.set_campaign_name("Neiman Marcus");
    campaign.set_pattern(".neimanmarcus.");
    campaign.set_percent(0.06);
    database.Insert(campaign);
  }
  {
    Campaign campaign;
    campaign.set_campaign_id(24);
    campaign.set_union_id(1);
    campaign.set_campaign_name("Neiman Marcus");
    campaign.set_pattern(".neimanmarcus.");
    campaign.set_percent(0.06);
    database.Insert(campaign);
  }
  {
    Campaign campaign;
    campaign.set_campaign_id(25);
    campaign.set_union_id(1);
    campaign.set_campaign_name("Bobbi Brown");
    campaign.set_pattern(".bobbibrowncosmetics.");
    campaign.set_percent(0.06);
    database.Insert(campaign);
  }
  {
    Campaign campaign;
    campaign.set_campaign_id(26);
    campaign.set_union_id(1);
    campaign.set_campaign_name("FinishLine");
    campaign.set_pattern(".finishline.");
    campaign.set_percent(0.06);
    database.Insert(campaign);
  }
  {
    Campaign campaign;
    campaign.set_campaign_id(27);
    campaign.set_union_id(1);
    campaign.set_campaign_name("Kiehls");
    campaign.set_pattern(".kiehls.");
    campaign.set_percent(0.06);
    database.Insert(campaign);
  }
}