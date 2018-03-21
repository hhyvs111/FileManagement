$(function() {
    var dateArray = []
    var currentDate = new Date()
    var currentYear = currentDate.getFullYear()
    var currentMonth = currentDate.getMonth() + 1
    var notifyQtChannel = null


    // 点击签到按钮, 设置当前日期为签到
    $("#js-just-qiandao").on('click', function() {
        $("#js-just-qiandao").addClass('actived');
        showLayer("qiandao-active", signIn);
        dateArray.push(`${currentDate.getFullYear()}-${currentDate.getMonth() + 1}-${currentDate.getDate()}`)

        if (notifyQtChannel) {
            notifyQtChannel(dateArray.join(','))
        }
    })

    // 当点击 body 区域, 关闭 Layer 组件
    $("body").on("click", ".close-qiandao-layer", function() {
        $(this).parents(".qiandao-layer").fadeOut()
    })

    // 绑定 Channel
    var webChannel = new QWebChannel(qt.webChannelTransport, function(channel) {
        // 已签到的日期集合
        var dateString = channel.objects.myObject.info || ''
        // 转换成数组
        dateArray = dateString.split(',')
        // 显示当前月日历
        showBox(currentYear, currentMonth)

        // 用于向 Channel 发送消息
        notifyQtChannel = channel.objects.myObject.callFromJS
    });

    // 设置当前日期
    $(".current-date").text(`${currentDate.getFullYear()}年${currentDate.getMonth() + 1}月${currentDate.getDate()}日`);

    // 下个月按钮
    $("#js-qiandao-historys").on("click", function() {
        if (currentMonth === 12) {
            currentYear += 1
            currentMonth = 1
        } else {
            currentMonth += 1
        }

        showBox(currentYear, currentMonth);
    })

    // 上个月按钮
    $("#js-qiandao-history").on("click", function() {
        if (currentMonth === 1) {
            currentYear -= 1
            currentMonth = 12
        } else {
            currentMonth -= 1
        }

        showBox(currentYear, currentMonth);
    })


    // 在指定日期签到
    function signIn(dateObject) {
        dateObject = dateObject || new Date()
        $(`.date-${dateObject.getFullYear()}-${dateObject.getMonth() + 1}-${dateObject.getDate()}`).addClass('qiandao');
    }

    // 显示 Layer 组件
    function showLayer(elClass, easing) {
        $(`.${elClass}`).fadeIn(easing)
    }

    // 显示日历
    function showBox(year, month) {
        // 获取一个月的开始是在星期几
        var monthFirst = new Date(year, parseInt(month - 1), 1).getDay();
        // 获取当前月的天数
        var totalDay = (new Date(year, parseInt(month), 0)).getDate();

        // 生成日历网格
        var _html = ''
        for (var i = 0; i < 42; i++) {
            _html += '<li><div class="qiandao-icon"></div></li>'
        }
        $("#js-qiandao-list").html(_html)

        // 找到所有日期
        var $dateLi = $("#js-qiandao-list").find("li");
        for (var i = 0; i < totalDay; ++i) {
            $dateLi.eq(monthFirst + i).addClass(`date-${year}-${month}-${i + 1}`);
            $dateLi.eq(monthFirst + i).addClass("date" + parseInt(i + 1));
        }

        // 在这些日期设置签到标志
        for (var date of dateArray) {
            var [year, month, days] = date.split('-');
            signIn(new Date(parseInt(year), parseInt(month) - 1, parseInt(days)))
        }
    };
})
