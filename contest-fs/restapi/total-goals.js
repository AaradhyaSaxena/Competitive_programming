
const axios = require('axios');

async function getTotalGoals(team, year) {
    let cnt = 0;
    let response = await axios.get(`https://jsonmock.hackerrank.com/api/football_matches?year=${year}&team1=${team}`);
    let result = response.data;
    let pages = result.total_pages;
    for(let i=0; i<pages; i++){
        response = await axios.get(`https://jsonmock.hackerrank.com/api/football_matches?year=${year}&team1=${team}&page=${i+1}`);
        result = response.data;
        for (let item of result.data){
            cnt += Number(item.team1goals);
        } 
    }
    
    response = await axios.get(`https://jsonmock.hackerrank.com/api/football_matches?year=${year}&team2=${team}`);
    result = response.data;
    pages = result.total_pages;
    for(let i=0; i<pages; i++){
        response = await axios.get(`https://jsonmock.hackerrank.com/api/football_matches?year=${year}&team2=${team}&page=${i+1}`);
        result = response.data;
        for (let item of result.data){
            cnt += Number(item.team2goals);
        } 
    }
    return cnt;
}
