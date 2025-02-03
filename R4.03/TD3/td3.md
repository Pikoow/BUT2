# TD3

## Partie 4

1. All fields of games.
db.games.find({})

2. Games id.
db.games.find({},{ id: true })

3. Titles and descriptions.
db.games.find({},{ title: true, description: true })

4. Titles.
db.games.find({},{ title: true })

5. Distinct titles.
db.games.distinct("title")

6. Years of release.*
db.games.find({},{ release_temp: true })
db.games.aggregate(
    [ { $project: {
        year: { $year: "release_temp" }
    } }
    ]
)

7. Games with a id less than 1000
db.games.find(
    { id: { $lt: 1000 } }
)

8. Games in 2000 and id greater than 48000.
db.games.find(
    {
        id: { $gt: 48000 },
        release_temp: { $gte: 2000-01-01, $lte: 2000-12-31 }
    }
)

9. Games titles with a id less than 1000.
db.games.find(
    {
        id: { $lt: 1000 },
        { title: true }
    }
)

10. Games sorted by title.
db.games.aggregate(
    [
        { $sort: { title: 1 } },
        { title: true }
    ]
)

11. Number of games per year.*
db.games.aggregate(
    { $group: { _id: "$release_temp", count: { $sum: 1 } } }
)

12. Number of games per year with at least 3 games.*
db.games.aggregate(
    [
        { $group: { _id: "$release_temp", count: { $sum: 1 } } },
        { $match: { count: { $gte: 3 } } }
    ]
)

13. Games which title ends by 2.*
db.game.find(
    { title: /2$/ }
)

14. Games which id is between 1000 and 2000.
db.games.find(
    {
        id: { $gte: 1000, $lte: 2000 },
    }
)
