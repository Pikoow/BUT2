# TD3

## Partie 4.1

1. All fields of game.
db.game.find({})

2. game id.
db.game.find({},{ id: true })

3. Titles and descriptions.
db.game.find({},{ title: true, description: true })

4. Titles.
db.game.find({},{ title: true })

5. Distinct titles.
db.game.distinct("title")

6. Years of release.*
db.game.find({},{ release_temp: true })

7. game with a id less than 1000
db.game.find(
    { id: { $lt: 1000 } }
)

8. game in 2000 and id greater than 48000.
db.game.find(
    {
        id: { $gt: 48000 },
        rel: { $gte: ISODate("2000-01-01T00:00:00.000Z"), $lte: ISODate("2000-12-31T00:00:00.000Z") }
    }
)

9. game titles with a id less than 1000.
db.game.find({ id: { $lt: 1000 } }, { title: true })

10. game sorted by title.
db.game.aggregate(
    [
        { $sort: { title: 1 } }
    ]
)

11. Number of game per year.*
db.game.aggregate([
    {
        $group: {
            _id: {$year: "$rel"},
            count: { $sum: 1 }
        }
    }
])

12. Number of game per year with at least 3 game.*
db.game.aggregate(
    [
        { $group: { _id: "$rel", count: { $sum: 1 } } },
        { $match: { count: { $gte: 3 } } }
    ]
)

13. game which title ends by 2.*
db.game.find(
    { title: /2$/ },
    { title: true }
)

14. game which id is between 1000 and 2000.
db.game.find(
    {
        id: { $gte: 1000, $lte: 2000 },
    },
    { id: true }
)

## Partie 4.2

1. use tp
2. db.people.insertMany([
       {id: 1, name: "Alice", age: 20 },
       {id: 1, name: "Bob", age: 35 }
   ])
3. show dbs
4. db
5. db.people.drop()
