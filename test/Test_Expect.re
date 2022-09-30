open BsMocha.Mocha;
open Expect.Expect;
open Expect.Comparisons;

[@bs.val] external _Array: Expect.Comparisons.Internal.constructor = "Array";
[@bs.val] external nan: float = "NaN";
[@bs.val] external seal: Js.t('a) => Js.t('a) = "Object.seal";
[@bs.val] external freeze: Js.t('a) => Js.t('a) = "Object.freeze";
[@bs.val] external infinity: float = "Infinity";

describe("Expect", () => {
  describe("Modifiers and Comparisons", () =>
    it("include -> members", () => {
      let (to_, include_) = (Expect.Chains.to_, Expect.Modifiers.include_);
      expect([|1, 2, 3|])->to_->include_->members([|1, 2|])->ignore;
    })
  );

  describe("Combos.End", () => {
    open Expect.Combos.End;
    it("to_deep_equal", () =>
      expect([{"a": 1}, {"a": 2}])->to_deep_equal([{"a": 1}, {"a": 2}])
    );
    it("to_be", () =>
      expect([{"a": 1}, {"a": 2}])->to_be([{"a": 1}, {"a": 2}])
    );
    it("to_be_a", () =>
      expect("foo")->to_be_a("string")
    );
    it("to_be_ok", () =>
      expect(true)->to_be_ok
    );
    it("to_include", () =>
      expect([|1, 2, 3|])->to_include(3)
    );
    it("to_equal", () =>
      expect(123)->to_equal(123)
    );
    it("to_eql", () =>
      expect({"a": 1, "b": 2})->to_eql({"a": 1, "b": 2})
    );
    it("to_be_above", () =>
      expect(2)->to_be_above(1.)
    );
    it("to_be_below", () =>
      expect(1)->to_be_below(2.)
    );
    it("to_be_at_least", () =>
      expect(1)->to_be_at_least(0.)
    );
    it("to_be_at_most", () =>
      expect(1)->to_be_at_most(2.)
    );
    it("to_be_within", () =>
      expect(1)->to_be_within(0., 2.)
    );
    it("to_be_instanceof", () =>
      expect([|1, 2, 3|])->to_be_instanceof(_Array)
    );
    it("to_have_property", () =>
      expect({"a": 1})->to_have_property("a", ~value=1)
    );
    it("to_have_own_property_descriptor", () =>
      expect({"a": 1})->to_have_own_property_descriptor("a")
    );
    it("to_be_of_length", () =>
      expect([|1, 2, 3, 4|])->to_be_of_length(4)
    );
    it("to_match", () =>
      expect("foobarfoofoobaz")
      ->to_match(Js.Re.fromString("^(foo|bar)+baz$"))
    );
    it("to_have_string", () =>
      expect("foobarfoofoobaz")->to_have_string("foobar")
    );
    it("to_throw", () =>
      expect(() =>
        Js.Exn.raiseError("blah")
      )->to_throw()
    );
    it("to_respond_to", () =>
      expect({"blah": () => ()})->to_respond_to("blah")
    );
    it("to_be_close_to", () =>
      expect(1.23456)->to_be_close_to(1.23, ~delta=0.01)
    );
    it("to_have_members", () =>
      expect([|1, 2, 3|])->to_have_members([|2, 3, 1|])
    );
    it("to_be_one_of", () =>
      expect(1)->to_be_one_of([|2, 3, 1|])
    );
    it("to_have_keys", () =>
      expect({"a": 1, "b": 2, "c": 3})->to_have_keys([|"a", "b", "c"|])
    );
    it("to_be_true", () =>
      expect(true)->to_be_true
    );
    it("to_be_false", () =>
      expect(false)->to_be_false
    );
    it("to_be_null", () =>
      expect(Js.null)->to_be_null
    );
    it("to_be_undefined", () =>
      expect(Js.undefined)->to_be_undefined
    );
    it("to_be_undefined", () =>
      expect(nan)->to_be_NaN
    );
    it("to_exist", () =>
      expect([])->to_exist
    );
    it("to_be_empty", () =>
      expect([||])->to_be_empty
    );
    it("to_be_sealed", () =>
      expect({"a": 1}->seal)->to_be_sealed
    );
    it("to_be_frozen", () =>
      expect({"a": 1}->freeze)->to_be_frozen
    );
    it("to_be_finite", () =>
      expect(1234)->to_be_finite
    );
    it_skip("to_be_finite", () => expect(infinity)->to_be_finite);
  });
});
