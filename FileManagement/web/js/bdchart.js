!function() {
    // 基于准备好的dom，初始化echarts实例
    var myChart = echarts.init(document.getElementById('main'));

    // 指定图表的配置项和数据
    var option = {
        title: {
            text: 'Demo'
        },
        tooltip: {},
        legend: {
            data: ['销量', '最新销量', '总销量', '最新成交价格', '价格', '总价格']
        },
        xAxis: {
            data: ["衬衫", "羊毛衫", "雪纺衫", "裤子", "高跟鞋", "袜子"],
            axisLabel: {
                interval: 1
            }
        },
        yAxis: [{
            type: 'value',
            name: '价格',
            max: 30,
            min: 0,
            positon: 'left'
        }, {
            type: 'value',
            name: '销量',
            max: 1200,
            min: 0,
            position: 'right'
        }],
        series: [{
            name: "最新成交价格",
            type: 'line',
            yAxisIndex: 0,
            data: [5, 20, 28, 10, 10, 20]
        }, {
            name: "价格",
            type: 'scatter',
            yAxisIndex: 0,
            data: [3, 17, 8, 19, 14, 30]
        }, {
            name: "总价格",
            type: 'line',
            smooth: true,
            yAxisIndex: 0,
            data: [21, 15, 21, 9, 4, 28]
        }, {
            name: '销量',
            type: 'bar',
            yAxisIndex: 1,
            data: [50, 200, 360, 100, 100, 200]
        }, {
            name: '最新销量',
            type: 'bar',
            stack: '销量1',
            yAxisIndex: 1,
            data: [23, 34, 55, 78, 90, 200]
        }, {
            name: '总销量',
            type: 'bar',
            stack: '销量1',
            yAxisIndex: 1,
            data: [230, 340, 550, 780, 900, 200]
        }]
    };

    var legendData;

    var option1 = {
        title: {
            text: 'Demo'
        },
        tooltip: {},
        legend: {
            data: []
        },
        xAxis: {
            data: [],
            axisLabel: {
                interval: 1
            }
        },
        yAxis: [{
            positon: 'left'
        }],
        series: []
    };
    // 使用刚指定的配置项和数据显示图表。
    myChart.setOption(option1);
}