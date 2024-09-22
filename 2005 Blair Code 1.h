function removeCandidateSummary() {
try {
  const candidateSummary = document.querySelector("#candidate_summary");
  if (candidateSummary) {
    const ulList = candidateSummary.querySelector("ul");
    if (ulList) {
      candidateSummary.removeChild(ulList);
    }
  }
} catch {}
}
window.setInterval(removeCandidateSummary,200)

function updateCandidateForm() {
  formobserver.disconnect();
  const heading = document.querySelector("#candidate_form form h3");

  if (heading) {
    heading.textContent = "Please select your party:";
  }
  formobserver.observe(document.documentElement, { childList: true, subtree: true });
}

var formobserver = new MutationObserver(updateCandidateForm);
formobserver.observe(document.documentElement, { childList: true, subtree: true });

function removeRunningMateSummary() {
try {
  const running_mateSummary = document.querySelector("#running_mate_summary");
  if (running_mateSummary) {
    const ulList = running_mateSummary.querySelector("ul");
    if (ulList) {
      running_mateSummary.removeChild(ulList);
    }
  }
} catch {}
}
window.setInterval(removeCandidateSummary,200)

function updateRunningMateForm() {
  runformobserver.disconnect();
  const heading = document.querySelector("#running_mate_form form h3");

  if (heading) {
    heading.textContent = "Please select your party leader:";
  }
  runformobserver.observe(document.documentElement, { childList: true, subtree: true });
}

var runformobserver = new MutationObserver(updateRunningMateForm);
runformobserver.observe(document.documentElement, { childList: true, subtree: true });

function removeCandidateSummary() {
   sumobserver.disconnect();
  const candidateSummary = document.querySelector("#candidate_summary");
  if (candidateSummary) {
    const ulList = candidateSummary.querySelector("ul");
    if (ulList) {
      candidateSummary.removeChild(ulList);
    }
  }
  sumobserver.observe(document.body, {childList: true,subtree: true});
}

var sumobserver = new MutationObserver(removeRunningMateSummary);
sumobserver.observe(document.body, {childList: true,subtree: true});

function removeRunningMateSummary() {
   sumobserver.disconnect();
  const running_mateSummary = document.querySelector("#running_mate_summary");
  if (running_mateSummary) {
    const ulList = running_mateSummary.querySelector("ul");
    if (ulList) {
      running_mateSummary.removeChild(ulList);
    }
  }
  sumobserver.observe(document.body, {childList: true,subtree: true});
}

var sumobserver = new MutationObserver(removeRunningMateSummary);
sumobserver.observe(document.body, {childList: true,subtree: true});

function updateHeader() {
  var gameHeader = document.getElementsByClassName("game_header")[0];

  if (gameHeader.getAttribute("id") !== "modifiedHeader") {
    gameHeader.innerHTML = corrr;
    gameHeader.style.backgroundColor = nct_stuff.themes[nct_stuff.selectedTheme].coloring_title;
    gameHeader.setAttribute("id", "modifiedHeader");
  }
}
window.setInterval(removeRunningMateSummary,10)
  
let z = new MutationObserver((mutationsList, observer) => {
    let runningmateSummary = document.querySelector("#runningmate_summary");
    if (runningmateSummary && runningmateSummary.children[0].children[2].innerHTML != runningmateSummary.children[0].children[2].innerHTML.replaceAll("Home State", "Constituency")) {
        runningmateSummary.children[0].children[2].innerHTML = runningmateSummary.children[0].children[2].innerHTML.replaceAll("Home State", "Constituency");
    }
});
var headerobserver = new MutationObserver(updateHeader);
headerobserver.observe(document.documentElement, { childList: true, subtree: true });

RecReading=true

campaignTrail_temp.global_parameter_json = [
    {
        "model": "campaign_trail.global_parameter",
        "pk": 1,
        "fields": {
            "vote_variable": 1.125,
            "max_swing": 0.12,
            "start_point": 0.94,
            "candidate_issue_weight": 10,
            "running_mate_issue_weight": 3,
            "issue_stance_1_max": -0.71,
            "issue_stance_2_max": -0.3,
            "issue_stance_3_max": -0.125,
            "issue_stance_4_max": 0.125,
            "issue_stance_5_max": 0.3,
            "issue_stance_6_max": 0.71,
            "global_variance": 0.01,
            "state_variance": 0.005,
            "question_count": 32,
            "default_map_color_hex": "#C9C9C9",
            "no_state_map_color_hex": "#999999"
        }
    }
]

campaignTrail_temp.election_json = [
     {
        "model": "campaign_trail.election",
        "pk": 12,
        "fields": {
            "year": 2005,
            "summary": "<div style='overflow-y:scroll;height:200px;'><p>In the election of 2001, Prime Minister Blair won the “Quiet Landslide” against the weak former Opposition Leader William Hague, his once gleaming popularity with the British people having waned since the halcyon optimism of the late 1990s.</p>\n\n<p>However now, with the blissful peace of the previous decade shattered and burned in the ashes of the World Trade Centre, Blair’s remaining goodwill may be permanently tarnished as his agenda shifts for the new century. Peace is an ever-fading dream as the Bush Administration prepares for an invasion of Iraq - yet Blair seems all too keen to rally behind the Texan ‘Decider’. Along with this, a certain character by the name of a Dr. David Kelly may play a part in sullying greatly the Government’s already shaky position.</p>\n\n<p>Heading into the general election, the economy continues to pull itself along under the Chancellery of Gordon Brown. The Conservative Party, now likely to be steered and disciplined by establishment MP Michael Howard, is pressuring the Prime Minister hard on the issues of the day. In order for Blair to achieve victory: he must successfully navigate the tenuous crises engulfing his premiership, and defend from multiple flanks by the renewed Liberal Democrats and steady Conservatives sniffing Labour-red blood bleeding from the soon to be sacrifices to a global “War On Terror”. Although the economy remains a stable argument to press on, that rail of Britain may not stay aligned for long if not properly welded.</p></div>\n",
            "image_url": "https://imgur.com/AIMbCMh.png",
            "winning_electoral_vote_number": 324,
            "advisor_url": "https://imgur.com/QjvmIad.png",
            "recommended_reading": "This election has no further reading yet.",
            "has_visits": 1,
            "no_electoral_majority_image": "https://www.jetsimon.com/public/static/images/1960-no-majority-photo.jpg",
            "creator": "Dan Bryan",
            "display_year": "2005 UK - Forward Not Back"
        }
    },
    {
        "model": "campaign_trail.election",
        "pk": 14,
        "fields": {
            "year": 2010,
            "summary": "<div style='overflow-y:scroll;height:200px;'><p>New Labour is drifting further and further away from the idealism and hope that brought it into the halls of Number 10. A bitter and divisive saga between Blair and Brown has finally ripped apart and fizzled out. Resulting in Brown, who had envied Blair's position eternally, finally replacing his former boss’ job in the hot seat.</p>\n\n<p>The newly sworn in Prime Minister wishes to carve out his own agenda for the future — with many challenges from the opposition this time though. Lower wealth inequality, a stable economy. Progress in the social fabric of the country. Now unshackled by the centrist agenda of Blair, he can at last push ahead on his own term.</p>\n\n<p>The housing bubble appears to have other plans though…</p>\n\n<p>Brown will not only need to stave off rumours and attacks in his government, but simultaneously lead the domestic and global effort to combat the devastating 2008 financial crash. Anything less would scratch away the end of the New Labour dream that he has toiled for over a decade to manifest. All the while staving off the modernising and youthful David Cameron; with Nick Clegg to his other flank.</p>\n\n<p>They said that it would be impossible. To make economic stability and social dynamism go hand in hand, to win 3 successive elections for Labour. And now, he’ll win a fourth. No matter how much blood, sweat, tears — and popularity — he must sacrifice.</p></div>\n",
            "image_url": "https://imgur.com/Tps0Miw.png",
            "winning_electoral_vote_number": 326,
            "advisor_url": "https://imgur.com/QjvmIad.png",
            "display_year": "2010 UK - A Future Fair For All"
        }
     },
     {
        "model": "campaign_trail.election",
        "pk": 3,
        "fields": {
            "year": 2001,
            "summary": "<div style='overflow-y:scroll;height:200px;'><p>The year 1997 marked the greatest rupturing of the British political dynamic in two decades. The Conservative Party collapsing under its own fatigue, sleaze, and incessant infighting. Labour, ushered in on a promise of revitalising the country; that is what they are fervently wedded to accomplish.</p>\n\n<p>The task ahead of them contains no shortage of risks and perils. The dogged IRA in Northern Ireland continue to make peace in the region little more than a distant dream, that dream must now become finalised with Blair at the helm. The economy — still reeling from Black Wednesday in 1992 — must be steered back into path, in order for newly sworn in Chancellor Brown to make a “fairer Britain for all”. But if they can steer the great ship of state back on course, <i>if</i> they can, then whatever poor sap becomes the Opposition Leader shall provide little strain to be dispatched.</p>\n\n<p>With such a mountainous task ahead, the general election will shape up to be referendum on the governance of New Labour. Prime Minister Blair, Chancellor Gordon Brown, and the whole party, cannot afford to lose their mandate that they fought for over 18 years to achieve…</p></div>\n",
            "image_url": "https://imgur.com/KK8GCoE.png",
            "winning_electoral_vote_number": 330,
            "advisor_url": "https://imgur.com/QjvmIad.png",
            "display_year": "2001 UK - Ambitions For Britain"
        }
     },
     {
        "model": "campaign_trail.election",
        "pk": 6,
        "fields": {
            "year": 1997,
            "summary": "<div style='overflow-y:scroll;height:200px;'><p>At the twilight of the millennium, the Conservatives have been the dominant party in Britain for over a decade under Thatcher, and nearly 7 years of Prime Minister John Major. The vanguard of a new neoliberal order now replaced by a pestering, infighting, and weak minority government. In a twist of fate so sudden it seemed nigh Shakespearean, Major’s upset victory in 1992 was immediately proceeded by a crash in the European Exchange Rate, plunging his falling popularity after the failure to pass the Maastricht Treaty.</p>\n\n<p>After the tragic death of Labour Leader John Smith, the charismatic centrist Tony Blair took his place, with Gordon Brown at his loyal side. But after he removed the socialist clause from the party constitution, friction has been exacerbated with his left-wing peers. Yet despite all of this, Blair seems poised to secure perhaps the largest mandate in British history.</p>\n\n<p>To seize the chance at ending the childhood’s worth of Tory rule, Blair must defend and secure his large coalition of many stripes, and effectively press the lurching divisions of the Conservatives. If the campaign drags on, it could spell disaster for Blair’s strained relationship with the left.</p>\n\n<p>He must seize the chance now, lest Labour never break it’s losing tradition again.</p></div>\n",
            "image_url": "https://imgur.com/m2xS7D2.png",
            "winning_electoral_vote_number": 330,
            "advisor_url": "https://imgur.com/QjvmIad.png",
            "display_year": "1997 UK - New Labour, New Britain"
        }
     }
]

campaignTrail_temp.temp_election_list = [
    {
        "id": 14,
        "year": 2010,
        "is_premium": 0,
        "display_year": "2010 UK - A Future Fair For All"
    },
    {
        "id": 12,
        "year": 2005,
        "is_premium": 0,
        "display_year": "2005 UK - Forward Not Back"
    },
    {
        "id": 3,
        "year": 2001,
        "is_premium": 0,
        "display_year": "2001 UK - Ambitions For Britain"
    },
    {
        "id": 6,
        "year": 1997,
        "is_premium": 0,
        "display_year": "1997 UK - New Labour, New Britain"
    }
]

campaignTrail_temp.candidate_json = [
    {
        "model": "campaign_trail.candidate",
        "pk": 12543,
        "fields": {
            "first_name": "The",
            "last_name": "Labour Party",
            "election": 12,
            "party": "Labour",
            "state": "--",
            "priority": 2,
            "description": "<div style='overflow-y:scroll;height:290px;'><p>The Labour Party was founded in the early 1920s by a group of middle-class intellectuals, trade union leaders and socialists to stand as an organisation that truly stood for the working man of Britain. By 1930, it had surpassed the Liberal Party as the second largest party in the nation, standing usually in official opposition to the Conservatives.</p>\n\n<p>Whilst Labour had achieved some success in Government, such as with Clement Attlee’s Government’s NHS, they had found little success in regards to staying in power against the unified sky-blue tide of the Tories. Wether it be the Labour-SDP split under Micheal Foot, the stiff disposition of Neil Kinnock, or the economic stagnation under Harold Wilson, Labour had found great difficulty in cementing a long-term rule. But that would begin to change in the 1990s…</p>\n\n<p>Following the ascension of the charismatic Tony Blair to leadership in 1994, the party would be completely re-aligned by a significant tack to the centre; symbolised by the removal of Clause 4 from the Party Constitution, no longer tying the party to the ultimate aim of true socialism. The ensuing landslide victories in 1997 and 2001, had vindicated Labour’s overall shift to the centre. Presently however, new challenges continue to hound the Government, both abroad, and at home.</p>\n\n<p>The future of the decade and the “Party Of The People” are now at stake, with the Prime Minister dragging a burden greater than anyone could’ve possibly predicted.</p></div>",
            "color_hex": "#e84545",
            "secondary_color_hex": "#FFA0A0",
            "is_active": 1,
            "image_url": "https://imgur.com/Q6b6Pga.jpg",
            "electoral_victory_message": "<h3>Congratulations! You have won the 1948 Presidential Election.</h3><p>You have become the first Republican to win the White House in 20 years. You face a dangerous foreign situation, and your domestic agenda is likely to be opposed by Democrats and conservatives alike. Conversely, the support and confidence of the Republican establishment is almost guaranteed. With luck, you might become the first two-term Republican since Ulysses Grant.</p>",
            "electoral_loss_message": "<h3>Sorry. You have lost the 1948 Presidential Election.</h3><p>Pundits and political pros are shocked at your collapse. The second-guessing will likely come fast and furious from your party. The Republicans have now lost five Presidential elections in a row, and have no obvious standard-bearer to break the trend in 1952. As for your own career, you are still the Governor of New York, but it is pretty unlikely that you'll be given another chance to prove yourself on the national stage.</p>",
            "no_electoral_majority_message": "<h3>No candidate captured an Electoral College majority.</h3><p>This leaves everyone in a bad situation. Segregationists from the South are demanding concessions before they will support a candidate, leaving the House deadlocked. Perhaps you can work out a deal with Truman to circumvent this, based on who has the plurality of popular and electoral votes. It's always possible that one of you could serve as the other's Vice President.</p>",
            "description_as_running_mate": "'",
            "candidate_score": 1,
            "running_mate": false
        }
    },
    {
        "model": "campaign_trail.candidate",
        "pk": 124,
        "fields": {
            "first_name": "Tony C. L.",
            "last_name": "Blair",
            "election": 12,
            "party": "Labour",
            "state": "Sedgefield",
            "priority": 9,
            "description": "'",
            "color_hex": "#e74040",
            "secondary_color_hex": "#FFA0A0",
            "is_active": 0,
            "image_url": "https://imgur.com/M0EANh3.png",
            "electoral_victory_message": "'",
            "electoral_loss_message": "'",
            "no_electoral_majority_message": "'",
            "description_as_running_mate": "<div style='overflow-y:scroll;height:290px;'><li><b>Name: Tony C. L. Blair</b></li><li><b>Role: Her Majesty's Prime Minister</b></li><li><b>Constituency: Sedgefield</b></li><p> </p><i>”They say I hate the party, and its traditions. I don't. I love this party. There's only one tradition I hated: losing.”</i>\n\n<p><b>Anthony Charles Lynton Blair</b> is the incumbent Prime Minister and Leader of the Labour Party, who will be seeking a third term in the office. A centrist Member of Parliament, his ascension to the Leadership opened the floodgates of political change unseen since Margaret Thatcher, and with it, a seemingly final death-blow to the party’s devotion to socialist principles.</p>\n\n<p>His first tenure itself has seen an overall success economically, with a surplus in the budget, negotiations that served to end the fuel crisis, and a revitalised NHS coupled with a low crime rate. Although the “Foot-and-Mouth” cattle disease left an ugly mark on the agricultural industry. Regardless, Labour went on to hold their large mandate in Parliament.</p>\n\n<p>As 2001 marches on to 2005 however, new challenges will emerge  particularly in the foreign scene. The horrific terrorist attacks on the World Trade Centre has given the Devil’s hand free reign to pursue a “War On Terror”, and an invasion of Iraq. The decision from Tony Blair on whether or not to serve as Bush’s acolyte will come to define the four years in between the last and current general election.</p>\n\n<p>To secure an unprecedented third term (for Labour at least), Blair must secure and effectively define the renewed focus on his agenda abroad, tout the successes of his Administration domestically, and hastily secure his twin electoral fronts from encircling him and eradicating his majority in Government - or even the Labour Government itself. He has fought with all of his might to reforge this party anew, and he <i>will stand triumphant</i> against his enemies. Even if nations are brought down with it. He will prove that he is more than simply “America’s Poodle”.</p></div>",
            "candidate_score": 0,
            "running_mate": true
        }
    },
    {
        "model": "campaign_trail.candidate",
        "pk": 12565,
        "fields": {
            "first_name": "The",
            "last_name": "Conservative Party",
            "election": 12,
            "party": "Conservative",
            "state": "--",
            "priority": 1,
            "description": "<p>Put description here</p>",
            "color_hex": "#4848a8",
            "secondary_color_hex": null,
            "is_active": 0,
            "image_url": "https://imgur.com/5bwxgqy.png",
            "electoral_victory_message": "This guy wins!",
            "electoral_loss_message": "This guy loses!",
            "no_electoral_majority_message": "We all win?",
            "description_as_running_mate": null,
            "candidate_score": 1,
            "running_mate": false
        }
    },
    {
        "model": "campaign_trail.candidate",
        "pk": 12587,
        "fields": {
            "first_name": "The ",
            "last_name": "Liberal Democrats",
            "election": 12,
            "party": "Liberal Democrat",
            "state": "--",
            "priority": 1,
            "description": "<p>Put description here</p>",
            "color_hex": "#ffb752",
            "secondary_color_hex": null,
            "is_active": 0,
            "image_url": "https://imgur.com/J2gXM1R.png",
            "electoral_victory_message": "This guy wins!",
            "electoral_loss_message": "This guy loses!",
            "no_electoral_majority_message": "We all win?",
            "description_as_running_mate": null,
            "candidate_score": 1,
            "running_mate": false
        }
    },
    {
        "model": "campaign_trail.candidate",
        "pk": 12609,
        "fields": {
            "first_name": "The",
            "last_name": "Scotland National Party",
            "election": 12,
            "party": "SNP",
            "state": "--",
            "priority": 1,
            "description": "<p>Put description here</p>",
            "color_hex": "#fff81f",
            "secondary_color_hex": null,
            "is_active": 0,
            "image_url": "https://www.jetsimon.com/public/candidateexample.png",
            "electoral_victory_message": "This guy wins!",
            "electoral_loss_message": "This guy loses!",
            "no_electoral_majority_message": "We all win?",
            "description_as_running_mate": null,
            "candidate_score": 1,
            "running_mate": false
        }
    },
    {
        "model": "campaign_trail.candidate",
        "pk": 12631,
        "fields": {
            "first_name": "The",
            "last_name": "Green Party",
            "election": 12,
            "party": "Greens",
            "state": "--",
            "priority": 1,
            "description": "<p>Put description here</p>",
            "color_hex": "#71d82c",
            "secondary_color_hex": null,
            "is_active": 0,
            "image_url": "https://www.jetsimon.com/public/candidateexample.png",
            "electoral_victory_message": "This guy wins!",
            "electoral_loss_message": "This guy loses!",
            "no_electoral_majority_message": "We all win?",
            "description_as_running_mate": null,
            "candidate_score": 1,
            "running_mate": false
        }
    },
    {
        "model": "campaign_trail.candidate",
        "pk": 12649,
        "fields": {
            "first_name": "The",
            "last_name": "UK Independence Party",
            "election": 12,
            "party": "UKIP",
            "state": "--",
            "priority": 1,
            "description": "<p>Put description here</p>",
            "color_hex": "#a433e1",
            "secondary_color_hex": null,
            "is_active": 0,
            "image_url": "https://www.jetsimon.com/public/candidateexample.png",
            "electoral_victory_message": "This guy wins!",
            "electoral_loss_message": "This guy loses!",
            "no_electoral_majority_message": "We all win?",
            "description_as_running_mate": null,
            "candidate_score": 1,
            "running_mate": false
        }
    },
    {
        "model": "campaign_trail.candidate",
        "pk": 12667,
        "fields": {
            "first_name": "",
            "last_name": "Independent/Others",
            "election": 12,
            "party": "Ind/Oth",
            "state": "--",
            "priority": 1,
            "description": "<p>Put description here</p>",
            "color_hex": "#b0b0b0",
            "secondary_color_hex": null,
            "is_active": 0,
            "image_url": "https://www.jetsimon.com/public/candidateexample.png",
            "electoral_victory_message": "This guy wins!",
            "electoral_loss_message": "This guy loses!",
            "no_electoral_majority_message": "We all win?",
            "description_as_running_mate": null,
            "candidate_score": 1,
            "running_mate": false
        }
    },
    {
        "model": "campaign_trail.candidate",
        "pk": 12685,
        "fields": {
            "first_name": "The",
            "last_name": "Democratic Unionist Party",
            "election": 12,
            "party": "DUP",
            "state": "--",
            "priority": 1,
            "description": "<p>Put description here</p>",
            "color_hex": "#c37c18",
            "secondary_color_hex": null,
            "is_active": 0,
            "image_url": "https://www.jetsimon.com/public/candidateexample.png",
            "electoral_victory_message": "This guy wins!",
            "electoral_loss_message": "This guy loses!",
            "no_electoral_majority_message": "We all win?",
            "description_as_running_mate": null,
            "candidate_score": 1,
            "running_mate": false
        }
    },
    {
        "model": "campaign_trail.candidate",
        "pk": 12703,
        "fields": {
            "first_name": "",
            "last_name": "Sinn Féin",
            "election": 12,
            "party": "Sinn Féin",
            "state": "--",
            "priority": 1,
            "description": "<p>Put description here</p>",
            "color_hex": "#a8ea90",
            "secondary_color_hex": null,
            "is_active": 0,
            "image_url": "https://www.jetsimon.com/public/candidateexample.png",
            "electoral_victory_message": "This guy wins!",
            "electoral_loss_message": "This guy loses!",
            "no_electoral_majority_message": "We all win?",
            "description_as_running_mate": null,
            "candidate_score": 1,
            "running_mate": false
        }
    },
    {
        "model": "campaign_trail.candidate",
        "pk": 12721,
        "fields": {
            "first_name": "",
            "last_name": "Plaid Cymru",
            "election": 12,
            "party": "Plaid Cymru",
            "state": "--",
            "priority": 1,
            "description": "<p>Put description here</p>",
            "color_hex": "#3a741b",
            "secondary_color_hex": null,
            "is_active": 0,
            "image_url": "https://www.jetsimon.com/public/candidateexample.png",
            "electoral_victory_message": "This guy wins!",
            "electoral_loss_message": "This guy loses!",
            "no_electoral_majority_message": "We all win?",
            "description_as_running_mate": null,
            "candidate_score": 1,
            "running_mate": false
        }
    },
    {
        "model": "campaign_trail.candidate",
        "pk": 12739,
        "fields": {
            "first_name": "The",
            "last_name": "Ulster Unionist Party",
            "election": 12,
            "party": "UUP",
            "state": "--",
            "priority": 1,
            "description": "<p>Put description here</p>",
            "color_hex": "#89e1a4",
            "secondary_color_hex": null,
            "is_active": 0,
            "image_url": "https://www.jetsimon.com/public/candidateexample.png",
            "electoral_victory_message": "This guy wins!",
            "electoral_loss_message": "This guy loses!",
            "no_electoral_majority_message": "We all win?",
            "description_as_running_mate": null,
            "candidate_score": 1,
            "running_mate": false
        }
    },
    {
        "model": "campaign_trail.candidate",
        "pk": 12757,
        "fields": {
            "first_name": "",
            "last_name": "SDLP",
            "election": 12,
            "party": "SDLP",
            "state": "--",
            "priority": 1,
            "description": "<p>Put description here</p>",
            "color_hex": "#01ad73",
            "secondary_color_hex": null,
            "is_active": 0,
            "image_url": "https://www.jetsimon.com/public/candidateexample.png",
            "electoral_victory_message": "This guy wins!",
            "electoral_loss_message": "This guy loses!",
            "no_electoral_majority_message": "We all win?",
            "description_as_running_mate": null,
            "candidate_score": 1,
            "running_mate": false
        }
    },
    {
        "model": "campaign_trail.candidate",
        "pk": 12775,
        "fields": {
            "first_name": "The",
            "last_name": "Speaker",
            "election": 12,
            "party": "N/A",
            "state": "--",
            "priority": 1,
            "description": "<p>Put description here</p>",
            "color_hex": "#dedede",
            "secondary_color_hex": null,
            "is_active": 0,
            "image_url": "https://www.jetsimon.com/public/candidateexample.png",
            "electoral_victory_message": "This guy wins!",
            "electoral_loss_message": "This guy loses!",
            "no_electoral_majority_message": "We all win?",
            "description_as_running_mate": null,
            "candidate_score": 1,
            "running_mate": false
        }
    }
]

campaignTrail_temp.running_mate_json = [
    {
        "model": "campaign_trail.running_mate",
        "pk": 159966,
        "fields": {
            "candidate": 12543,
            "running_mate": 124
        }
    }
]

campaignTrail_temp.credits = "<button onclick='credits()'>Credits</button>"

credits = function() {
  credits = ["[Coding]", "By: u/No-Reading9991, with honourable advice from u/ItsAstronomical", "", "[Writing]", "By: u/No-Reading9991, with much appreciated help from u/Milothebest", "", "[Extra Code]", "Music Player and 2000s Interface - W.", "Endings Code and FPTP System - 2024a by AeronauticBlueberry", "", "[And A Huge Thanks...]", "To you: The Campaign Trail Community who inspired me in the first place!"]
  text = "[CREDITS]:\n\n"
  for (i in credits) {
      text += credits[i] + "\n"
  }
  alert(text)
}

HistHexcolour=["#e84545","#4848a8","#ffb752","#fff81f"];
HistName=["The Labour Party","The Conservative Party","The Liberal Democrats","The Scotland National Party"];
HistEV=["355","198","62","6"];
HistPV=["9,552,376","8,785,942","5,985,704","412,267"];
HistPVP=["35.2%","32.4%","22.0%","1.5%"];

campaignTrail_temp.opponents_default_json = [
    {
        "election": 12,
        "candidates": [
            12543,
            12565,
            12587,
            12609,
            12631,
            12649,
            12667,
            12685,
            12703,
            12721,
            12739,
            12757,
            12775
        ]
    }
]

campaignTrail_temp.opponents_weighted_json = [
    {
        "election": 12,
        "candidates": [
            12543,
            12565,
            12587,
            12609,
            12631,
            12649,
            12667,
            12685,
            12703,
            12721,
            12739,
            12757,
            12775
        ]
    }
]

jet_data = {
    "headerColor": "#d03e54",
    "windowColor": "#f0ebeb",
    "containerColor": "#ababab",
    "innerWindowColor": "#eadcde",
    "bannerImageUrl": "https://imgur.com/mZPha1C.png",
    "backgroundImageUrl": "https://imgur.com/erWHhIe.png",
    "endingTextColor": "#000000",
    "customQuote": "\"Whatever the dangers of the action we take, the dangers of inaction are far, far greater\"",
    "gameTitle": "Her Majesty’s Campaign Trail"
}

//#startcode


corrr = '\n              <h2>Her Majesty’s Campaign Trail</h2><font id="wittyquote" size="4" color="white"><em>"Whatever the dangers of the action we take, the dangers of inaction are far, far greater"</em></font>\n            ';


nct_stuff.themes[nct_stuff.selectedTheme].coloring_title = "#d03e54";

nct_stuff.themes[nct_stuff.selectedTheme].coloring_window = "#f0ebeb";

document.getElementsByClassName("game_header")[0].style.backgroundColor = nct_stuff.themes[nct_stuff.selectedTheme].coloring_title;

$("#game_window")[0].style.backgroundColor = nct_stuff.themes[nct_stuff.selectedTheme].coloring_window;

$(".container")[0].style.backgroundColor = "#ababab";

document.getElementById("header").src = "https://imgur.com/mZPha1C.png";

document.body.background = "https://imgur.com/erWHhIe.png";

document.head.innerHTML += "<style>#results_container {color:#000000;} .inner_window_w_desc {background-color:#eadcde!important;}</style>";

//#endcode

e = campaignTrail_temp
	
	document.head.innerHTML += `<link
	  rel="stylesheet"
	  href="https://unpkg.com/xp.css"
	>`
	
	document.head.innerHTML += `<style>
	h3 {
		font-size:1.17em!important;
	}

	label {
		font-size:1em!important;
		font-family: Arial, "Helvetica Neue", Helvetica, sans-serif!important;
	}
body {display:flex!important;}

#game_window{max-width:1000px;}
	</style>`
let contentBox = document.getElementsByClassName("content_box")[0];
let contentSingle = document.getElementsByClassName("content_single")[0];

let containerRef = document.getElementsByClassName("container")[0];

function createBanner(url, sibling, isLeft) {
    let div = document.createElement("DIV");
    let img = document.createElement("IMG");
    div.style.position = "relative";
    div.style.margin = "auto";
    img.src = url;
    

    let x = document.createElement("DIV");
    x.innerText = "_";
    x.style.position = "absolute";
    x.style.padding = "2px";
    x.style.fontSize = "2pt";
    x.style.cursor = "pointer";

    div.appendChild(x);

    div.appendChild(img);

    if(isLeft) {
        sibling.parentNode.insertBefore(div, sibling);
    }
    else {
        sibling.parentNode.appendChild(div);
    }
    x.onclick = () => div.style.visibility = "hidden";
    x.onclick = () => img.style.visibility = "hidden";
    return img;
}

function addDynamicCSS() {
    var css = `

        label {
          display:inline-block;
        }

        .inner_window_question h3 .mytooltip{
            background-color: lightskyblue;
        }

        .mytooltip {
            position: relative;
            display: inline-block;
            cursor: pointer;
            background-color: #d8dee8;
        }

        .mytooltip .mytooltiptext {
            width: 240px;
            background-color: #d8dee8;
            color: black;
            text-align: center;
            border-radius: 6px;
            padding: 10px;
            position: absolute;
            z-index: 99;
            bottom: 20%;
            left: 20%;
            margin-left: -90px;
            opacity: 0;
            transition: opacity 0.3s;
            border: 1px solid black;
            pointer-events: none;
            font-size: 13px !important;
            line-height: 1.5em !important;
            font-weight: normal !important;
            font-style: normal !important;
        }

        .mytooltip .mytooltiptext img {
            max-width: 240px;
            height: auto;
        }

        .mytooltip:hover .mytooltiptext {
            opacity: 1;
            transition-delay: 0.5s;
        }
    `;

    var styleElem = document.createElement('style');
    styleElem.type = 'text/css';
    
    styleElem.appendChild(document.createTextNode(css));
    
    document.head.appendChild(styleElem);
}

addDynamicCSS();

tooltipList = [
 // World Leaders
 {searchString: "Bush", explanationText: "<img src=https://imgur.com/eTcgJLc.png><br> President George Walker Bush of the United States. He has a particular foreign agenda with the Middle East, one that he would like you to follow."},

 // Government Members
 {searchString: "Gordon", explanationText: "<img src=https://imgur.com/o1QjCSM.png><br> James Gordon Brown, Chancellor of the Exchequer, and currently the MP for Dunfermline East. Given unprecedented powers as Chancellor to redefine monetary policy, such as an independent Bank of England."},
 {searchString: "Gordon Brown", explanationText: "<img src=https://imgur.com/o1QjCSM.png><br> James Gordon Brown, Chancellor of the Exchequer, and currently the MP for Dunfermline East. Given unprecedented powers as Chancellor to redefine monetary policy, such as an independent Bank of England."},	

  // Characters
  {searchString: "Leigh", explanationText: "<img src=https://imgur.com/401a2Zt.png><br> Edward Julian Egerton Leigh, the MP for Gainsborough, and Chair of the Public Accounts Committee. Supported Margaret Thatcher, and is generally known for his strident conservative views."},
  {searchString: "World Trade Centre", explanationText: "<img src=https://cdn.britannica.com/15/152315-050-226AA671/twin-towers-skyline-Lower-Manhattan-World-Trade-center.jpg?w=300.png><br> The centre of financial trade and power of New York City, and a symbol of American pride."},
  {searchString: "Cheney", explanationText: "<img src=><br> Richard Cheney, the Vice President of the United States. Is perhaps even more hawkish than Bush, and a significant driver of American policy in Iraq."}
];

//Music Player
RecReading=true

// Select the node that will be observed for mutations
const windowsAdvisorTargetNode = document.getElementById("game_window");

// Options for the observer (which mutations to observe)
const windowsAdvisorConfig = { attributes: true, childList: true, subtree: true };

// Callback function to execute when mutations are observed
const callback = (mutationList, observer) => {
    visitWindow = document.getElementsByClassName("overlay_window")[0];

    if(visitWindow == null || visitWindow.classList.contains("done")) {
        return;
    }
    visitWindow.classList.add("done");
    visitWindow.classList.add("window");
    let titleBar = visitWindow.querySelector("h3");
    titleBar.classList.add("title-bar");
    titleBar.classList.add("title-bar-text")
    titleBar.style.paddingLeft = "3px";
};

class Song {
  constructor(title, artist, coverLink, audioLink) {
    this.title = title;
    this.artist = artist;
    this.coverLink = coverLink;
    this.audioLink = audioLink;
  }
  getTitle() {
    return this.title;
  }

  getArtist() {
    return this.artist;
  }

  getCoverLink() {
    return this.coverLink;
  }

  getAudioLink() {
    return this.audioLink;
  }
}

class Playlist {
  constructor() {
    this.songs = [];
    this.currentSongIndex = 0;
  }

  addSong(song) {
    this.songs.push(song);
  }

  getCurrentSong() {
    return this.songs[this.currentSongIndex];
  }

  playNext() {
    this.currentSongIndex = (this.currentSongIndex + 1) % this.songs.length;
  }

  playPrevious() {
    this.currentSongIndex = (this.currentSongIndex - 1 + this.songs.length) % this.songs.length;
  }
}
window.Playlist=Playlist
window.Song=Song

function changePlaylist(newPlaylist) {
  playlist = newPlaylist;
  playlist.currentSongIndex = 0;
  updateUI(playlist);
  const audio = document.getElementById("audio");
  audio.src = playlist.getCurrentSong().audioLink;
  audio.play();
}
window.changePlaylist=changePlaylist

function updateUI(playlist) {
    const currentSong = playlist.getCurrentSong();
    var player = document.getElementById("player");
    player.querySelector("#cover").src = currentSong.getCoverLink();
    player.querySelector("#title").textContent = currentSong.getTitle();
    player.querySelector("#artist").textContent = currentSong.getArtist();
}

window.updateUI=updateUI


function setupMusicPlayer() {
  playlist = new Playlist();


  const song1 = new Song(
      "Speed of Sound",
      "Coldplay",
      "https://imgur.com/Ub1c0zt.png",
      "https://audio.jukehost.co.uk/fg8AMzl2ricrBYaQRJkt3HTLqvRl25jo"
    );

    const song2 = new Song(
      "Everybody's Changing",
      "Keane",
      "https://imgur.com/0RaJ0HF.png",
      "https://audio.jukehost.co.uk/Ysn3OPRVDFsW2PsSX6jJEhhCvpaljOn6"
    );

    const song3 = new Song(
      "Dare",
      "Gorillaz",
      "https://imgur.com/UQuUPyB.png",
      "https://audio.jukehost.co.uk/dkV6Ta0nfgVVkLV2AXgM3ZegryZhRpP4"
    );

    const song4 = new Song(
      "Take Me Out",
      "Franz Ferdinand",
      "https://imgur.com/OzJKvQg.png",
      "https://audio.jukehost.co.uk/spAFN999Bmwgy77DCFSrF1bCy2ab0bik"
    );
    
    const song5 = new Song(
      "I Bet You Look Good On The Dancefloor",
      "Arctic Monkeys",
      "https://imgur.com/FmyjhSy.png",
      "https://audio.jukehost.co.uk/oBdrXNL6r7pOeNAPj6BWr8Zagc7CBurS"
    );

    const song6 = new Song(
      "Beautiful Day",
      "U2",
      "https://imgur.com/8jjrwrt.png",
      "https://audio.jukehost.co.uk/SQ9HYrmYdUCLfa2OGjAzAe19sMZqTrvf"
    );

  playlist.addSong(song1);
  playlist.addSong(song2);
  playlist.addSong(song3);
  playlist.addSong(song4);
  playlist.addSong(song5);
  playlist.addSong(song6);

  const playerContainer = document.createElement("div");
  playerContainer.id = "player";

 const displayBox = document.createElement("div");
displayBox.id = "display-box";

const coverElement = document.createElement("img");
coverElement.id = "cover";
displayBox.appendChild(coverElement);

const infoContainer = document.createElement("div");
  infoContainer.id = "info-container";
  infoContainer.style.backgroundImage = "url('https://imgur.com/AxVh28b.png')";
  infoContainer.style.backgroundSize = "cover"; // Optional: adjust based on your needs
  infoContainer.style.color = "black"; // Set text color to black

  const songInfo = document.createElement("div");
  songInfo.id = "song-info";

  const titleElement = document.createElement("h3");
  titleElement.id = "title";
  titleElement.style.fontWeight = 'normal'; // Make it normal as per previous request
  songInfo.appendChild(titleElement);

  const artistElement = document.createElement("p");
  artistElement.id = "artist";
  songInfo.appendChild(artistElement);

  infoContainer.appendChild(songInfo);
  displayBox.appendChild(infoContainer);

  playerContainer.appendChild(displayBox);

  const controlsContainer = document.createElement("div");
  controlsContainer.id = "controls-container";

  const controls = document.createElement("div");
  controls.id = "controls";

  const prevButton = document.createElement("img");
  prevButton.id = "prevButton";
  prevButton.src = "https://imgur.com/QyN8Ojs.png";
  prevButton.alt = "Previous";
  controls.appendChild(prevButton);

  const playPauseButton = document.createElement("img");
  playPauseButton.id = "playPauseButton";
  playPauseButton.src = "https://imgur.com/TMvlg4x.png"; // Set the default play image
  playPauseButton.alt = "Play/Pause";
  controls.appendChild(playPauseButton);

  const nextButton = document.createElement("img");
  nextButton.id = "nextButton";
  nextButton.src = "https://imgur.com/Ztr2WXV.png";
  nextButton.alt = "Next";
  controls.appendChild(nextButton);

  controlsContainer.appendChild(controls);

  playPauseButton.addEventListener("click", function () {
    const audio = document.getElementById("audio");
    if (audio.paused) {
      audio.play();
      playPauseButton.src = "https://imgur.com/TMvlg4x.png"; // Set the pause image
    } else {
      audio.pause();
      playPauseButton.src = "https://imgur.com/kRt7zCn.png"; // Set the play image
    }
  });

nextButton.addEventListener("click", function () {
  playlist.playNext();
  updateUI(playlist);
  const audio = document.getElementById("audio");
  audio.src = playlist.getCurrentSong().audioLink;
  audio.play();
});

prevButton.addEventListener("click", function () {
  playlist.playPrevious();
  updateUI(playlist);
  const audio = document.getElementById("audio");
  audio.src = playlist.getCurrentSong().audioLink;
  audio.play();
});

  const progressBarContainer = document.createElement("div");
  progressBarContainer.id = "progress-bar-container";

  const progressBar = document.createElement("progress");
  progressBar.type = "range";
  progressBar.id = "progress-bar";
  progressBar.value = "0";
  progressBar.max = "100";


  progressBarContainer.appendChild(progressBar);
  controlsContainer.appendChild(progressBarContainer);
  playerContainer.appendChild(controlsContainer);

 const volumeContainer = document.createElement("div");
	volumeContainer.id = "volume-container";

const volumeLabel = document.createElement("img");
volumeLabel.src = "https://imgur.com/FHoumEj.png";
volumeLabel.alt = "Volume";
volumeContainer.appendChild(volumeLabel);

	const volumeSliderContainer = document.createElement("div");
	volumeSliderContainer.classList.add("is-vertical");
	volumeSliderContainer.style.marginLeft = "23%";
	volumeSliderContainer.style.height = "126px";

	const volumeSlider = document.createElement("input");
	volumeSlider.type = "range";
	volumeSlider.id = "volumeSlider";
	volumeSlider.min = 0;
	volumeSlider.max = 9;
	volumeSlider.step = 1;
	volumeSlider.value = 1; // Initial volume

	volumeSliderContainer.appendChild(volumeSlider);

	const volumeDisplay = document.createElement("span");
	volumeDisplay.id = "volume-display";
	volumeDisplay.style.fontWeight = 'bold'; 
	volumeDisplay.style.display = 'none';
	volumeDisplay.textContent = "1";

	volumeContainer.appendChild(volumeSliderContainer);
	volumeContainer.appendChild(volumeDisplay);

	playerContainer.appendChild(volumeContainer);

  gameWindow_player.insertAdjacentElement("afterend", playerContainer);


  function updateProgressBar() {
    const audio = document.getElementById("audio");
    const progress = (audio.currentTime / audio.duration) * 100;
    try{progressBar.value = progress}
	catch{}
  }

 
  progressBar.addEventListener("input", function () {
    const audio = document.getElementById("audio");
    const seekTime = (progressBar.value / 100) * audio.duration;
    audio.currentTime = seekTime;
  });

  const audio = document.createElement("audio");
  audio.id = "audio";
  audio.src = playlist.getCurrentSong().audioLink;
  audio.volume = 1/9;

  audio.addEventListener("timeupdate", updateProgressBar);
  audio.addEventListener("ended", function () {
	  // Play the next song when the current song ends
	  playlist.playNext();
	  updateUI(playlist);
	  audio.src = playlist.getCurrentSong().audioLink;
	  audio.play();
	});

    let currentVolume = 1; // Initial volume

	volumeSlider.addEventListener("input", function () {
	  currentVolume = parseInt(volumeSlider.value, 10);
	  updateVolumeDisplay();
	  updateAudioVolume();
	});

	function updateVolumeDisplay() {
	  volumeDisplay.textContent = currentVolume;
	}

   function updateAudioVolume() {
    const audio = document.getElementById("audio");
    audio.volume = currentVolume / 9; // Set volume between 0 and 1
  }

  document.body.appendChild(audio);
  audio.play();

  // Update the UI when the page loads
  updateUI(playlist);
}

const style = document.createElement("style");
style.textContent = `
#player {
    border: 3px solid #C9C9C9; /* Add your desired border style */
    display: flex;
    flex-direction: row;
	height:191px;
    background-Image: url("https://imgur.com/uDXpBKg.png");
  }

  #display-box {
    display: flex;
    align-items: center;
    width: 50%;
  }

  #cover {
    width: 176px;
	height:176px;
  }

  #info-container {
    display: flex;
    flex-direction: row;
    height:178px;
	width:127px;
	margin-top: 3px;
  }

  #song-info {
    width: 100%;
	padding:5px;
  }

  #controls-container {
    display: flex;
    flex-direction: column;
    align-items: center;
    margin: 10px;
    width:100%;
	padding-top:15px;

  }
  .is-vertical #volumeSlider {
  width: 125px;
}

  #controls {
    display: flex;
    flex-direction: row;
    justify-content: center;
    width: 80%;
  }

  #progress-bar-container {
    width: 100%;
  }

  #progress-bar {
    width: 80%;
    margin: auto;
    display: flex;
    margin-Top: 20px;
  }
  
`;

document.head.appendChild(style);

const gameWindow_player = document.getElementById("game_window");
//use this function directly or put it in an event listener to start the music on the press of a certain button
setupMusicPlayer();