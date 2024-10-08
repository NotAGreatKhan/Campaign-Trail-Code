function addDynamicCSS() {
    var css = `

        label {
          display:inline;
        }

        .inner_window_question h3 .mytooltip{
            background-color: lightred;
        }

        .mytooltip {
            position: relative;
            display: inline-block;
            cursor: pointer;
            background-color: #ffd6db;
        }

        .mytooltip .mytooltiptext {
            width: 240px;
            background-color: #ffd6db;
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
	{searchString: "Bush", explanationText: "<img src=https://imgur.com/eTcgJLc.png> President George Walker Bush of the United States. He has a particular foreign agenda with the Middle East, one that he would like you to follow."},

	// Government Members
	{searchString: "Gordon,", explanationText: "<img src=https://imgur.com/o1QjCSM.png> James Gordon Brown, Chancellor of the Exchequer, and currently the MP for Dunfermline East. Given unprecedented powers as Chancellor to redefine monetary policy, such as an independent Bank of England."},
	{searchString: "Gordon Brown,", explanationText: "<img src=https://imgur.com/o1QjCSM.png> James Gordon Brown, Chancellor of the Exchequer, and currently the MP for Dunfermline East. Given unprecedented powers as Chancellor to redefine monetary policy, such as an independent Bank of England."},	

        // Characters
        {searchString: "Leigh", explanationText: "<img src=https://imgur.com/401a2Zt.png> Edward Julian Egerton Leigh, the MP for Gainsborough, and Chair of the Public Accounts Committee. Supported Margaret Thatcher, and is generally known for his strident conservative views."},
        {searchString: "World Trade Centre", explanationText: "<img src=https://cdn.britannica.com/15/152315-050-226AA671/twin-towers-skyline-Lower-Manhattan-World-Trade-center.jpg?w=300.png> The centre of financial trade and power of New York City, and a symbol of American pride."},
        {searchString: "Cheney", explanationText: "<img src=> Richard Cheney, the Vice President of the United States. Is perhaps even more hawkish than Bush, and a significant driver of American policy in Iraq."},
];
