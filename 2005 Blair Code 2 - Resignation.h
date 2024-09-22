var Resign = 0;

campaignTrail_temp.cyoa = true
cyoAdventure = function(a) {
ans = campaignTrail_temp.player_answers[campaignTrail_temp.player_answers.length - 1]
    if(ans == 12542){
      Resign += 1;
    }
    if(ans == 12798){
      Resign += 1;
    }
    if(ans == 12814){
      Resign += 1;
    }
    if(ans == 12819){
      Resign += 1;
    }
    if(ans == 12824){
      Resign += 1;
    }
    if(ans == 12828){
      Resign += 1;
    }
    if(ans == 12834){
      Resign += 1;
    }   
}


//Questions
    if(Resign >= 7){
    campaignTrail_temp.questions_json[13] = {
    "model": "campaign_trail.question",
    "pk": 100000,
    "fields": {
        "priority": 0,
        "description": "[February, 2005] Your government is in damage control. Your Chancellor is eyeing your job with no shortage of brazenness and envy. And now, <i>now</i>, your position may have just reached its expiry date. A cold melancholy has settled in the apartment complexes of Downing Street. As you go around your fellow cabinet members, their responses to you are strange in their unison and foreboding: “Prime Minister, we would like to support you all the way, but I just don’t believe that is sustainable anymore. It’s time for new blood”. It can’t be. It – it cannot be. There’s got to be something you can do.",
        "likelihood": 1
      }
    }
  } 

    if(Resign >= 7){
    campaignTrail_temp.questions_json[14] = {
    "model": "campaign_trail.question",
    "pk": 100007,
    "fields": {
        "priority": 0,
        "description": "[February, 2005] The day you knew would come, but not so fast. It has finally arrived. Outside the large black door of No. 10 for your final time, it is time to make your resignation speech. It is time to sign off your premiership. Once and for all…",
        "likelihood": 1
      }
    }
  }
    if(Resign >= 7){
    campaignTrail_temp.questions_json[31] = {
    "model": "campaign_trail.question",
    "pk": 100011,
    "fields": {
        "priority": 0,
        "description": "Well, that was ugly. But that is in the past now, Brown. With you heading the party, it falls to you to finish this election campaign off. What will you do to convince the voters to back Labour at this pivotal penultimate hour?",
        "likelihood": 1
      }
    }
  }


//Answers
    {
        "model": "campaign_trail.answer",
        "pk": 100001,
        "fields": {
            "question": 100000,
            "description": "I… I can’t… I can’t go on. If my own cabinet doesn’t even support me, then it really is over..."
        }
    },
    {
        "model": "campaign_trail.answer",
        "pk": 100002,
        "fields": {
            "question": 100000,
            "description": "No… No, no, no. This won’t be how I go down, I won’t let it. I’m fighting this out! I need to, for the country, for New Labour. Everything we have accomplished together. Everything we could do in our grasp, and we’re just going to let go of that? No, I will contest whatever motion of No Confidence, whatever leadership challenge. I don’t care! I’m not… I’m not going out like this."
        }
    },
    {
        "model": "campaign_trail.answer",
        "pk": 100008,
        "fields": {
            "question": 100007,
            "description": "“…In the years to come, wherever I am, whatever I do, I’m with you. Wishing you well. I’m wanting you to win. You’re the future now – so make the most of it”."
        }
    },
    {
        "model": "campaign_trail.answer",
        "pk": 100012,
        "fields": {
            "question": 100011,
            "description": "Our first priority should always be the economy. Because by maintaining a strong economy, the lives of the whole of Britain shall stay prosperous, and you then have the opportunity to invest in the future. Emphasise our economic record heavily."
        }
    },
    {
        "model": "campaign_trail.answer",
        "pk": 100013,
        "fields": {
            "question": 100011,
            "description": "Now that Tony is no longer leading the party, we can tactfully shift our position on, and away from, Iraq. The war itself has garnered great unpopularity since the military operation, so we need to be tactful in how we approach this. We’ll avoid bringing it up, but when asked, we’ll support the withdrawal of troops once order is restored — instead of the full nation building."
        }
    },
    {
        "model": "campaign_trail.answer",
        "pk": 100014,
        "fields": {
            "question": 100011,
            "description": "Let’s really lay it thick into the Tories – just like my old days in the ‘90s – we’ll hit them on their last record in government, their frankly ludicrous policies. The whole nine yards. Let’s finish this campaign."
        }
    }


//Feedback
    {
        "model": "campaign_trail.answer_feedback",
        "pk": 100003,
        "fields": {
            "answer": 100001,
            "candidate": 12543,
            "answer_feedback": "You did your best Tony. Now though, it’s time for a new man to lead the country. Probably not a surprise as to who it will be."
        }
    },
    {
        "model": "campaign_trail.answer_feedback",
        "pk": 100004,
        "fields": {
            "answer": 100002,
            "candidate": 12543,
            "answer_feedback": "It’s over Tony, you’ll just have to accept that. We hate to see you go, but that’s just how it is. It’s another man’s time now."
        }
    },
    {
        "model": "campaign_trail.answer_feedback",
        "pk": 100009,
        "fields": {
            "answer": 100008,
            "candidate": 12543,
            "answer_feedback": "Fair sailing, Tony Blair."
        }
    },
    {
        "model": "campaign_trail.answer_feedback",
        "pk": 100015,
        "fields": {
            "answer": 100012,
            "candidate": 12543,
            "answer_feedback": "As the economy continues to chug along, and as your record as Chancellor shines to the average voter, this angle is always going to be your strongest turf. Hopefully you can pull a victory after the resignation. To save New Labour."
        }
    },
    {
        "model": "campaign_trail.answer_feedback",
        "pk": 100016,
        "fields": {
            "answer": 100013,
            "candidate": 12543,
            "answer_feedback": "Whilst a good idea on paper, the occupation has gone on for over 2 years. This is an issue that will just haunt you if you’re elected. At least you were Chancellor until now, instead of say, Foreign Secretary. It also helps you against the Conservatives, who fully support the war."
        }
    },
    {
        "model": "campaign_trail.answer_feedback",
        "pk": 100017,
        "fields": {
            "answer": 100014,
            "candidate": 12543,
            "answer_feedback": "A true Gordon Brown forté. You don’t quite have the same energy as you did then, but they are decently effective at pressuring the still-reeling Opposition."
        }
    }


//Global Answer Effects
    {
        "model": "campaign_trail.answer_score_global",
        "pk": 100005,
        "fields": {
            "answer": 100001,
            "candidate": 12543,
            "affected_candidate": 12543,
            "global_multiplier": -0.1
        }
    },
    {
        "model": "campaign_trail.answer_score_global",
        "pk": 100006,
        "fields": {
            "answer": 100002,
            "candidate": 12543,
            "affected_candidate": 12543,
            "global_multiplier": -0.105
        }
    },
    {
        "model": "campaign_trail.answer_score_global",
        "pk": 100010,
        "fields": {
            "answer": 100008,
            "candidate": 12543,
            "affected_candidate": 12543,
            "global_multiplier": -0.005
        }
    },
    {
        "model": "campaign_trail.answer_score_global",
        "pk": 100018,
        "fields": {
            "answer": 100012,
            "candidate": 12543,
            "affected_candidate": 12543,
            "global_multiplier": 0.05
        }
    },
    {
        "model": "campaign_trail.answer_score_global",
        "pk": 100019,
        "fields": {
            "answer": 100013,
            "candidate": 12543,
            "affected_candidate": 12543,
            "global_multiplier": 0.002
        }
    },
    {
        "model": "campaign_trail.answer_score_global",
        "pk": 100020,
        "fields": {
            "answer": 100014,
            "candidate": 12565,
            "affected_candidate": 12565,
            "global_multiplier": -0.05
        }
    }
