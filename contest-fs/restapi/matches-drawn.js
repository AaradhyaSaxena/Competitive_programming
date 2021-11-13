const axios = require('axios');

async function getNumDraws(year) {
    let counter =0;
    let response = await axios(`https://jsonmock.hackerrank.com/api/football_matches?year=${year}`);
    let result = response.data;
    let {total_pages} = result;
    for(let i=0; i<total_pages; i++){
        response = await axios(`https://jsonmock.hackerrank.com/api/football_matches?year=${year}&page=${i+1}`);
        result = response.data;
        for(const item of result.data){
            if(item.team1goals === item.team2goals){
                counter++;
            }
        }
    }
    return counter;
}