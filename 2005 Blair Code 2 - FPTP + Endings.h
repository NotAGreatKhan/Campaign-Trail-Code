distributeSeatsUK = () => {
    //Only let this function run once per game.
    e.distributedseats;
    if (e.distributedseats === 1) {return;}
    e.distributedseats = 1;

    // Helper functions
    function get_state_threshold(state) {
        // input: state id of current state
        // output: float between 0.0 and 1.0, determining the minimum
        // percent to pass the states' threshold
        //if (state == 475) {return 0.1}
        //if (state == 460) {return 0}

        // Conservative thresholds
        if (state == 12506 && c == 12565) {return 0.25} // Scotland
        if (state == 12446 && c == 12565) {return 0.275} // North East England
        if (state == 12452 && c == 12565) {return 0.35} // North West England 
        // Lib Dem thresholds
        if (state == 12482 && c == 12587) {return 0.325} // London
        if (state == 12488 && c == 12587) {return 0.35} // South East 
        if (state == 12500 && c == 12587) {return 0.375} // Wales
        if (state == 12446 && c == 12587) {return 0.38} // North East England
        if (state == 12452 && c == 12587) {return 0.25} // North West England
        if (state == 12458 && c == 12587) {return 0.33} // Yorkshire
        if (state == 12476 && c == 12587) {return 0.3} // East of England
        if (state == 12464 && c == 12587) {return 0.35} // East Midlands
        // Thresholds
        if (state == 12446) {return 0.099} // North East England
        if (state == 12452) {return 0.1} // North West England
        if (state == 12458) {return 0.11} // Yorkshire
        if (state == 12464) {return 0.11} // East Midlands
        if (state == 12470) {return 0.11} // West Midlands
        if (state == 12476) {return 0.11} // East of England
        if (state == 12482) {return 0.12} // London
        if (state == 12488) {return 0.12} // South East
        if (state == 12494) {return 0.12} // South West
        if (state == 12500) {return 0.11} // Wales
        if (state == 12506) {return 0.09} // Scotland
        if (state == 12512) {return 0.05} // Northern Ireland
        return 0;
    }

    function get_guarenteed_seats(state, c) {
        // input: state id and candidate id
        // output: int, number of seats c is guarenteed in state
        //if (state == 466 && c == 80) {return 2}
        //if (state == 460 && c == 80) {return 20}
        // Conservatives
        if (state == 12506 && c == 12565) {return 1} // Scotland
        if (state == 12446 && c == 12565) {return 1} // North East England
        if (state == 12452 && c == 12565) {return 8} // North West England        
        // Independent/Others
        if (state == 12500 && c == 12667) {return 1} // Wales        
        // Lib Dems elsewhere
        if (state == 12464 && c == 12587) {return 1} // East Midlands
        if (state == 12482 && c == 12587) {return 8} // London
        if (state == 12500 && c == 12587) {return 3} // Wales
        if (state == 12446 && c == 12587) {return 1} // North East England
        if (state == 12452 && c == 12587) {return 5} // North West England
        if (state == 12458 && c == 12587) {return 2} // Yorkshire
        if (state == 12476 && c == 12587) {return 2} // East of England
        if (state == 12506 && c == 12587) {return 2} // Scotland        
        // Northern Ireland
        if (state == 12512 && c == 12685) {return 9}
        if (state == 12512 && c == 12703) {return 5}
        if (state == 12512 && c == 12757) {return 3}
        if (state == 12512 && c == 12739) {return 1}
        // Lib Dems in South of England
        if (state == 12494 && c == 12587) {return 3} // South West
        if (state == 12488 && c == 12587) {return 5} // South East
        // Speaker in Scotland
        if (state == 12506 && c == 12775) {return 1}
        return 0;
    }

    // zero out national seat counts
    for(var ci = 0; ci < e.final_overall_results.length; ci++) {
        e.final_overall_results[ci].electoral_votes = 0;
    }

    //loop over each state's results
    for(var i = 0; i < e.final_state_results.length; i++) {
        var state = e.final_state_results[i].state;
        
        // Store the index of the state in the final_state_results array.
        var fsrIndex = e.final_state_results.map(f=>f.state).indexOf(state);
        
        // Store a read only copy of the state's results (for convenience)
        var stateData = e.final_state_results[fsrIndex];

        // Get the state's total popular votes and seats.
        var tot_state_votes = e.states_json[e.states_json.map(f=>f.pk).indexOf(state)].fields.popular_votes;
        var seats_left = e.states_json[e.states_json.map(f=>f.pk).indexOf(state)].fields.electoral_votes;
        
        // Begin tracking how many votes are actually competitive.
        var competitivevotes = 0;

        // First loop over each party in state
        for(var j = 0; j < stateData.result.length; j++) {
            var c = stateData.result[j].candidate;

            // Zero out seats in that state
            e.final_state_results[fsrIndex].result[j].electoral_votes = 0;

            // Count the candidate's votes if and only if they pass the state threshold
            var cur_c_votes = stateData.result[j].votes * 1.0;
            var cur_c_to_totvotes = cur_c_votes / tot_state_votes
            if (cur_c_to_totvotes >= get_state_threshold(state)) {
                competitivevotes += cur_c_votes
            }

            // Add guarenteed seats to minor parties (greens?)
            var guarenteed_seats = get_guarenteed_seats(state, c)
            if (guarenteed_seats > 0) {
                seats_left -= guarenteed_seats

                // Give the party those seats in that state.
                e.final_state_results[fsrIndex].result[j].electoral_votes += guarenteed_seats;

                // Then add the seats to the national total.
                e.final_overall_results[e.final_overall_results.map(f=>f.candidate).indexOf(c)].electoral_votes += guarenteed_seats;
            
            }

        }

        // By default, this is * 1.0. 

        var votes_per_seat = (competitivevotes * 1.6) / seats_left

        // Second loop: Actually add seats
        for(var j = 0; j < stateData.result.length; j++) {
            // Calculate what percent of the seats should be won.
            var c = stateData.result[j].candidate;
            var cur_c_votes = stateData.result[j].votes;
            var seats = Math.floor(cur_c_votes * 1.0 / votes_per_seat)

            // Calculate your percent of votes.
            var cur_c_votes = stateData.result[j].votes * 1.0;
            var cur_c_to_totvotes = cur_c_votes / tot_state_votes

            // Add seats if there are any to add and you meet the threshold
            if (seats > 0 && cur_c_to_totvotes >= get_state_threshold(state)) {
                seats_left -= seats;

                e.final_state_results[fsrIndex].result[j].electoral_votes += seats;
                e.final_overall_results[e.final_overall_results.map(f=>f.candidate).indexOf(c)].electoral_votes += seats;
            }
        }

        // Give any remaining seats to first place. simulate FPTP biasing towards first
        if (seats_left > 0) {
            var c = stateData.result[0].candidate;
            e.final_state_results[fsrIndex].result[0].electoral_votes += seats_left;
            e.final_overall_results[e.final_overall_results.map(f=>f.candidate).indexOf(c)].electoral_votes += seats_left;
        }
    }

}

let observerRunning = false;
let changeChartRunning = false;
let mcaHeightRunning = false;
let processedNodes = new Set();

async function handleMutations(mutationsList, observer) {
    if (observerRunning) return;
    observerRunning = true;

    // stop observing
    observer.disconnect();

    // addScrollbar
    const overallResult = document.getElementById('overall_result');
    if (overallResult && !processedNodes.has(overallResult)) {
        overallResult.style.overflow = 'auto';
        const buttons = document.querySelectorAll('#view_electoral_map, #answer_select_button, #ok_button, #final_election_map_button');
        const handleClick = () => {
            overallResult.style.overflow = 'auto';
        };
        buttons.forEach(button => button.addEventListener('click', handleClick));
        processedNodes.add(overallResult);
    }

    // changechart
    if (!changeChartRunning) {
        changeChartRunning = true;
        const elementIDs = ["overall_vote_statistics", "state_result_data_summary", "overall_details_container"];
        for(let id of elementIDs) {
            let element = document.getElementById(id);
            if (element && !processedNodes.has(element)) {
                let overallthing = element.innerHTML;
                overallthing = overallthing.replace("Electoral Votes","Allocated Seats");
                overallthing = overallthing.replace("Candidate","Party List");
                element.innerHTML = overallthing;
                processedNodes.add(element);
            }
        }
        changeChartRunning = false;
    }
 // mcaHeight
    if (!mcaHeightRunning) {
        mcaHeightRunning = true;
        let results_container = document.getElementById("results_container");
        let chart = document.getElementById("myChart");
        if (results_container && !processedNodes.has(results_container)) {
            if (!chart){
                results_container.style.height = "98%";
                results_container.style.overflow = "scroll";
            } else {
                let mca = document.getElementById("main_content_area");
                if (mca) {
                    mca.style.height = "80%";
                }
            }
            processedNodes.add(results_container);
        }
        mcaHeightRunning = false;
    }

    // Resume observing
    observer.observe(document.documentElement, { childList: true, subtree: true });
    observerRunning = false;
}

let singleObserver = new MutationObserver(handleMutations);
singleObserver.observe(document.documentElement, { childList: true, subtree: true });



endingPicker = (out, totv, aa, quickstats) => {

    function setImage(url) {
        if(used != true) {
            setInterval(function () {
            img = document.getElementsByClassName("person_image")[0];
            if (img != null) {
                img.src = url;
                clearInterval(interval);
            }
        }, 100);
    }
}

distributeSeatsUK();

    //out = "win", "loss", or "tie" for your candidate
//totv = total votes in entire election
//aa = all final overall results data
//quickstats = relevant data on candidate performance (format: your candidate's electoral vote count, your candidate's popular vote share, your candidate's raw vote total)

if (quickstats[0]<324 && aa[0].candidate == 12543) {
return "<h3>As Big Ben strikes 10, we can predict that the Conservatives have won the election, in a definitive repudiation of Tony Blair’s government.</h3><p>As David Dimbleby’s voice rings out on the television screen, all you feel is a stinging ache. The ever-optimistic shred of your mind clings to the desperate volition of at least a narrow victory being possible, but then the seats come in. Seat after seat. Colleague after colleague, falling to a new Tory government. Your ideals of a renewed, safer nation, burnt to ashes under the heels of that damn war.</p><p>What exactly went wrong? Was it Iraq? Was it those blasted attacks that Howard threw at you? Whatever it was, you have lost the election, that’s all that truly matters to your unyielding ambitious conscience. It really is over. Perhaps you were not “winning the argument that economic dynamism and social justice must go hand in hand” after all. You call Howard to congratulate him for his victory, and prepare to give your last speech outside that now-looming black door.</p><p>You will almost certainly resign as party leader following this defeat, your merit as an election-winning machine definitively exhausted after this. It is likely your loyal Chancellor Gordon Brown will succeed you for leadership, and provide a more measured (if stale) voice to the Opposition. It is unlikely that Labour will secure power again for a while, though you are aware it is premature to make hurried conclusions now.</p><p>After more than a childhood’s worth of Conservative rule, you did not even get to serve half of that time as Prime Minister. And now, those snivelling sky-blue Tories will scurry their way back into government.</p><p>You can almost feel John Smith’s sorrowful bitterness at you, as you stare into the void. Into the abyss.</p>"
setImage("https://imgur.com/0bqHDaj.png");
} 

else if (aa[0].electoral_votes < 324 && aa[1].electoral_votes < 324 && aa[2].electoral_votes < 324 && aa[3].electoral_votes < 324 && aa[4].electoral_votes < 324 && aa[5].electoral_votes < 324 && aa[6].electoral_votes < 324 && aa[7].electoral_votes < 324 && aa[8].electoral_votes < 324 && aa[9].electoral_votes < 324 && aa[10].electoral_votes < 324 && aa[11].electoral_votes < 324 && aa[12].electoral_votes < 324 && aa[13].electoral_votes < 324) {
return "<h3>As Big Ben strikes 10, we can predict a hung Parliament for Britain, this is certainly a let down for Labour.</h3><p>It seems as though you, and the nation, share the utter surprise evident in David Dimbleby’s voice. Nobody really anticipated this outcome, save for the Liberal Democrat hopefuls wishing to finally break into government. Whilst this is certainly disappointing for national security reforms you were hoping to make, there is an avenue for continued governance with a coalition via the Liberal Democrats if you are able to form such a government. Regardless of the outcome, it is clear the LibDems are significant winners tonight, and will make governance a multi-faceted task to perform.</p><p>Your mind wonders the many possibilities that could’ve unfolded, anything, just anything, better than this folly of a deadlock. What really went wrong? Was it the Iraq War? Was it the blasted attacks hurled at you? Whatever it was, it is likely you will resign as party leader within the next 1 to 2 years at the maximum.</p><p>Just when you thought you were past the thick of it, another roadblock has been lobbed at you. Coalition negotiations are going to be tough, but depending on the seat shares, there could be a viable way out for you. Strap in, Tony, because it’s going to be quite the few days ahead of you…</p>"
setImage("https://imgur.com/ZVxm7Y7.png");
} 

else if (quickstats[0] >= 324 && quickstats[0]<340) {
return "<h3>As Big Ben strikes 10, we can predict that the Labour Party has won, though with a narrow majority in Parliament.</h3><p>As David Dimbleby’s voice rings out on the television screen, trepidation grips your conscience and the Labour HQ. You have clinched a victory, but you have bled a lot of colleagues and seats as a result of this gruelling campaign, no doubt due to the Iraq War and the simple fact that Ian Duncan Smith is no longer existent in national politics.</p><p>With a majority secured, you may be able to pursue those national security reforms you have desired for so long now. With how slim your majority is in Parliament though, don’t count on it to go too smoothly. All it would take is a significant amount of whip suspensions, resignations and by-election defeats, to eradicate your majority all together. Suffice to say, Gordon Brown is definitely going to be crossing his fingers whenever you resign in the near future.</p><p>You fought with all you could, but in the end, only the most pitiful dividend was handed out. Best of luck, Prime Minister, you’re sure as hell going to need it.</p>"
setImage("https://imgur.com/2Vtwwm7.png");
} 

else if (quickstats[0] >= 340 && quickstats[0]<355) {
return "<h3>As Big Ben strikes 10, we can predict that the Labour Party has won, and with a modest majority in Parliament.</h3><p>As David Dimbleby’s voice rings out on the television screen, you let out a small, and reserved, sigh of relief. You have retained your position as PM. Even in spite of this, you have bled a lot of support to the Liberal Democrats and Conservatives. A lackluster performance, by your standards. At least for now, you can rest easy knowing your majority can survive some resignations here and there.</p><p>With this majority secured, you may be able to pursue those national security reforms you have desired for so long now. Though with how controversial they’ll be, don’t bet all of your cards on it going smoothly with your modest majority. Gordon Brown will definitely be crossing his fingers whenever you resign.</p><p>You fought through the battle with all you could, but only a tepid endorsement of your agenda was given to you. Best of luck, Prime Minister, because you sure as hell are going to need it.</p>"
setImage("https://imgur.com/2Vtwwm7.png");
} 

else if (quickstats[0] >= 355 && quickstats[0]<370) {
return "<h3>As Big Ben strikes 10, we can predict that the Labour Party has won, and with a strong majority in Parliament.</h3><p>As David Dimbleby’s voice rings out on the television screen, you let out perhaps the biggest sigh of relief of your premiership. Despite the significant bleeding of support, you have held on to your position as PM. Though for someone such as yourself, this isn’t exactly a spectacular performance.</p><p>Now that you have snatched a secure Parliament, you should have little trouble in pursuing those national security reforms you have desired for a while now. Take some caution though, you have still bled a lot of colleagues as a result of this election. Your Chancellor is still going to be crossing his fingers for this, that’s for sure.</p><p>You fought the battle with all you could, yet the lion’s share was handed out hesitantly and mildly. Best of luck for your remaining years, Prime Minister, you’ll have a tough last few years ahead of you.</p>"
setImage("https://imgur.com/2Vtwwm7.png");
} 

else if (quickstats[0] >= 370 && quickstats[0]<419) {
return "<h3>As Big Ben strikes 10, we can predict that the Labour Party has won, and that a landslide is likely in the election.</h3><p>As David Dimbleby’s voice rings out on the television screen, a resounding cheer erupts throughout the crowd gathered to witness the results. You’ve done it! Despite the festering pressures abroad, despite the growing controversy of your premiership, and despite the renewed strength of the Tories and Liberal Democrats, you persevered to carry three successive landslide victories for your party. Your colleagues will certainly be thanking you for aiding in their retaining of their seats.</p><p>With this commanding majority in Parliament, you should have little difficulty in passing those reforms on national security you have desired for so long. Whenever you do end up resigning, Gordon Brown will definitely be satisfied with the majority you have left for him. It seems that at least for now, New Labour will sustain itself for at least 5 years to come. Perhaps, even more.</p><p>You fought, you triumphed, and in the end, the lion’s share has handsomely fallen into your grasp. Whilst I will of course wish you the best of luck, it seems you can likely do anything with this victory. Good luck Tony!</p>"
setImage("https://imgur.com/7SD1Vg5.png");
} 

else if (quickstats[0] >= 419 && quickstats[0]<500) {
return "<h3>As Big Ben strikes 10, we can predict that the Labour Party has won in a landslide, surpassing their record in 1997!</h3><p>As David Dimbleby’s voice rings out on the television screen, the Labour Party HQ shudders and rumbles under the enthusiastic — almost riotous — jiving of the crowds. The amateur dancing of the members, unequivocally dispelling any jitter suspected throughout election night.</p><p>Initially, your scepticism at the exit poll gets the better of you. But then, the seats come in... Constituency after constituency, MP after MP; A sea of red washing over the map, engulfing the entirety of the country. The sky-blue wave of the Conservatives washed away, and scattered by the orange locusts of Liberal Democrats. The Blairite legacy having fully cemented itself in the national zeitgeist.</p><p>Succeeding in such a total, and dominating, command over the House of Commons, you should have little trouble passing those national security reforms you have desired to obtain in the new terror-stricken millenia. It goes without saying that Gordon Brown is going to thank you when he takes over your office in the next Parliament.</p><p>After all of these long years, your fight in the political battlefield has yielded a triumph greater than any leader before you.</p><p>John Smith would be proud — you’re sure he would. If only Kier Hardie were here too. To see what we have achieved.</p>"
setImage("https://imgur.com/7SD1Vg5.png");          
} 

else if (quickstats[0] >= 500) {
return "<h3>A Conversation between Prime Minister Tony Blair, and Communications Director Alastair Campbell. March 17, 2003, the day before the anti-war vote.</h3><p>[CAMPBELL]: This isn’t looking good, Tony, the upcoming commons vote, it could be the biggest rebellion of MPs in our government’s history.</p><p>[BLAIR]: Even more than the one for the Higher Education Act?</p><p>[CAMPBELL]: Even more than that.</p><p>[BLAIR]: There has to be something we can do to stem the flow of this… I hate to say this, but we may need to use that <i>other</i> intelligence MI5 was able to collate.</p><p>[CAMPBELL]: You mean, Operation <i>BIGSHOT</i>?</p><p>[BLAIR]: I’m afraid so, Alastair.</p><p>[CAMPBELL]: Damnit, it shouldn’t have even come close to this. I’ll get Peter in here, and talk it with him, should get the job done.</p><p>[BLAIR]: Good, we have to win this thing. For us. For Labour.</p><p>-End of Transcription.</p>"
setImage("https://imgur.com/VfQvbGe.png");
}

else if ((campaignTrail_temp.player_answers == 100008) && quickstats[0]<324 && aa[0].candidate == 12543) {
return "<h3>As Big Ben strikes 10, we can predict that the Conservatives have won this election, in a second and final death-blow to New Labour</h3>"
setImage("https://imgur.com/ydfBei4.png");
}

else {
return "<h3>Error Handler</h3><p>Contact No-Reading</p>"
}

}
campaignTrail_temp.multiple_endings=true
